#include "../include/philo.h"

void	*monitor(void *data)
{
	t_structs *structs;
	int total_times_to_eat;

	structs = (t_structs *)data;
	total_times_to_eat =  structs->data->ntimes_to_eat * structs->data->num_philos;
	while (1)
	{
		if (structs->data->num_times_eaten == total_times_to_eat)
		{
			printf("\033[0;33mnum times to eat reached\n\033[0;31m");
			exit(EXIT_SUCCESS);
			return ((void *)1);
		}
	}
}

int	supervisor(t_philo *philo)
{
	if (philo->last_time_ate > philo->data->die_time)
	{
		// printf("%lld\n", philo->last_time_ate);
		printf("%d reached death time\n", philo->index);
		exit(1);
	}
	return (0);
	// if (philo->is_dead == 1)
		// return 1;
}

void	*routine(void *phil)
{
	t_philo *philo;

	philo = (t_philo *)phil;
	while (1)
	{
		supervisor(philo);
		take_forks(philo);
		if (philo->im_locked == 1)
			eat(philo);
		think(philo);
	}
	return (NULL);
}

int	threading(t_structs *structs)
{
	int	i;
	pthread_t monitor_thread;

	i = -1;
	if (structs->data->ntimes_to_eat != -1)
	{
		structs->data->num_times_eaten = 0;
		pthread_create(&monitor_thread, NULL, &monitor, structs);
	}
	while (++i < structs->data->num_philos)
	{
		structs->philos[i].last_time_ate = get_time() - structs->data->start_time;
		pthread_create(&structs->philos[i].threads, NULL, &routine, &structs->philos[i]);
	}
	pthread_join(monitor_thread, NULL);
	while (i--)
		pthread_join(structs->philos[i].threads, NULL);
	return 1;
}
