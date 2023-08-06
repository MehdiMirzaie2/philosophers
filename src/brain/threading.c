/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:41:08 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/08/06 22:19:59 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*monitor(void *data)
{
	t_structs	*structs;
	int			total_times_to_eat;

	structs = (t_structs *)data;
	total_times_to_eat = structs->data->ntimes_to_eat
		* structs->data->num_philos;
	while (1)
		if (structs->data->num_times_eaten == total_times_to_eat)
			return ((void *)1);
}

void	*supervisor(void *stru)
{
	t_structs	*structs;
	u_int64_t	time;
	int			i;

	structs = (t_structs *) stru;
	while (1)
	{
		i = 0;
		while (i < structs->data->num_philos)
		{
			time = get_time() - structs->philos[i].last_time_ate;
			if (time > structs->data->die_time)
			{
				print_message(DIED, i + 1, structs->philos);
				return ((void *)1);
			}
			i++;
		}	
	}
}

void	*routine(void *phil)
{
	t_philo *const	philo = (t_philo *)phil;

	if (philo->first == 1)
	{
		pthread_mutex_lock(&philo->my_mutex);
		pthread_mutex_lock(&(*philo->right_fork));
		print_message(FORK, philo->index, philo);
		print_message(FORK, philo->index, philo);
		eat(philo);
	}
	while (1)
	{
		take_forks(philo);
		if (philo->did_i_take_my_fork == 1 && philo->did_i_take_right_fork == 1)
			eat(philo);
		think(philo);
	}
	return (NULL);
}

int	threading(t_structs *structs)
{
	int			i;
	pthread_t	monitor_thread;
	pthread_t	superviour_thread;

	i = -1;
	if (structs->data->ntimes_to_eat != -1)
	{
		structs->data->num_times_eaten = 0;
		pthread_create(&monitor_thread, NULL, &monitor, structs);
	}
	while (++i < structs->data->num_philos)
		pthread_create(&structs->philos[i].threads,
			NULL, &routine, &structs->philos[i]);
	pthread_create(&superviour_thread, NULL, &supervisor, structs);
	// pthread_join(monitor_thread, &structs->data->someone_died);
	pthread_join(monitor_thread, &structs->data->reached_n_eat);
	if ((long int)structs->data->reached_n_eat == 1)
		return (1);
	pthread_join(superviour_thread, &structs->data->someone_died);
	if ((long int)structs->data->someone_died == 1)
		return (2);
	while (i--)
		pthread_join(structs->philos[i].threads, NULL);
	return (3);
}
