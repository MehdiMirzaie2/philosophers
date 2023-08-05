/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etsd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:29:44 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/08/05 22:59:22 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	take_forks(t_philo *philo)
{
	static pthread_mutex_t	lock = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&lock);
	if (philo->did_i_take_my_fork == 1 && (*philo->right_islocked) == 0)
	{
		*philo->right_islocked = 1;
		philo->did_i_take_right_fork = 1;
		pthread_mutex_lock(&(*philo->right_fork));
		print_message(FORK, philo->index, philo);
	}
	else if (philo->did_i_take_right_fork == 1 && philo->my_fork_is_locked == 0)
	{
		philo->my_fork_is_locked = 1;
		philo->did_i_take_my_fork = 1;
		pthread_mutex_lock(&philo->my_mutex);
		print_message(FORK, philo->index, philo);
	}
	else if (*philo->right_islocked == 0)
	{
		*philo->right_islocked = 1;
		philo->did_i_take_right_fork = 1;
		pthread_mutex_lock(&(*philo->right_fork));
		print_message(FORK, philo->index, philo);
	}
	pthread_mutex_unlock(&lock);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->my_mutex);
	pthread_mutex_unlock(&(*philo->right_fork));
	philo->my_fork_is_locked = 0;
	philo->did_i_take_my_fork = 0;
	philo->did_i_take_right_fork = 0;
	*philo->right_islocked = 0;
	philo->first = 0;
}

void	increase_neaten(t_philo *philo)
{
	static pthread_mutex_t	lock = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&lock);
	philo->data->num_times_eaten += 1;
	philo->n_times_i_ate += 1;
	pthread_mutex_unlock(&lock);
}

void	eat(t_philo *philo)
{
	print_message(EATING, philo->index, philo);
	if (!philo->first)
		philo->last_time_ate = get_time();
	my_usleep(philo->data->eat_time);
	drop_forks(philo);
	increase_neaten(philo);
	print_message(SLEEPING, philo->index, philo);
	my_usleep(philo->data->sleep_time);
}

void	think(t_philo *philo)
{
	u_int64_t	iterator;

	iterator = 0;
	print_message(THINKING, philo->index, philo);
	while (iterator < philo->data->eat_time)
	{
		my_usleep(philo->data->eat_time / 16);
		take_forks(philo);
		if (philo->did_i_take_my_fork == 1 && philo->did_i_take_right_fork == 1)
			return ;
		iterator += (philo->data->eat_time / 16);
	}
}
