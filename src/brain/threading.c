/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:41:08 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/08/06 19:08:41 by mehdimirzai      ###   ########.fr       */
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
			return (NULL);
}

void *supervisor(void *stru)
{
	t_structs	*structs;
	u_int64_t	time;
	int			i;
	
	structs = (t_structs *) stru;
				// printf("%lld\n", get_time() - structs->philos[1].last_time_ate + 1);
				// printf("%lld\n", get_time() - structs->philos[3].last_time_ate + 1);
	while (1)
	{
		i = 0;
		while (i < structs->data->num_philos)
		{
			time = get_time() - structs->philos[i].last_time_ate;
			if (time > structs->data->die_time)
			{
				print_message(DIED, i + 1, structs->philos);
				structs->data->someone_died = 1;
				return (NULL);
			}
			i++;
		}	
	}
}

// int	supervisor(t_philo *philo)
// {
// 	u_int64_t time = get_time() - philo->last_time_ate;
// 	if (time >= philo->data->die_time)
// 	{
// 		print_message(DIED, philo->index, philo);
// 		philo->data->someone_died = 1;
// 		return (1);
// 	}
// 	return (0);
// }

void	*routine(void *phil)
{
	t_philo *const		philo = (t_philo *)phil;
	static pthread_mutex_t	lock = PTHREAD_MUTEX_INITIALIZER;

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
		pthread_mutex_lock(&lock);
		if (philo->data->someone_died == 1)
			return ((void *)1);
		pthread_mutex_unlock(&lock);
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
	void*		thread_return_value;

	i = -1;
	if (structs->data->ntimes_to_eat != -1)
	{
		structs->data->num_times_eaten = 0;
		pthread_create(&monitor_thread, NULL, &monitor, structs);
	}
	while (++i < structs->data->num_philos)
	{
		pthread_create(&structs->philos[i].threads,
			NULL, &routine, &structs->philos[i]);
	}
	pthread_create(&superviour_thread, NULL, &supervisor, structs);
	pthread_detach(monitor_thread);
	pthread_detach(superviour_thread);
	// while (i--)
	// {
	// 	pthread_join(structs->philos[i].threads, NULL);
	// 	// if (structs->data->someone_died == 1)
	// 	// 	return (2);
	// }
	while (i--)
	{
		pthread_join(structs->philos[i].threads, &thread_return_value);
		if ((long int)thread_return_value == 1)
			return (2);
	}
	return (1);
}
