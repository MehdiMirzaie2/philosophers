#include "../include/philo.h"

void	*monitor(void *dat)
{
	t_data *data;
	int total_times_to_eat;

	data = (t_data *)dat;
	total_times_to_eat =  data->ntimes_to_eat * data->num_philos;
	while (1)
	{
		if (data->num_times_eaten == total_times_to_eat)
		{
			printf("num times to eat reached\n");
			exit(EXIT_SUCCESS);
			return ((void *)1);
		}
		printf("\033[0;33m%d monitor n times to eat\n\033[0;31m", data->num_times_eaten);
	}
}

// int	supervisor(t_philo *philo)
// {
// 	if (philo->is_dead == 1)
// 		return 1;
// }

void	*routine(void *phil)
{
	t_philo *philo;

	philo = (t_philo *)phil;
	while (1)
	{
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
		pthread_create(&monitor_thread, NULL, &monitor, &structs->data);
	}
	while (++i < structs->data->num_philos)
	{
		// structs->philos[i].index = i;
		structs->philos[i].last_time_ate = structs->data->start_time;
		pthread_create(&structs->philos[i].threads, NULL, &routine, &structs->philos[i]);
	}
	while (i--)
		pthread_join(structs->philos[i].threads, NULL);
	return 1;
}
