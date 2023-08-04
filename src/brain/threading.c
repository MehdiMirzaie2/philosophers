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
	if ((get_time() - philo->last_time_ate) > philo->data->die_time)
	{
		printf("%d reached death time\n", philo->index);
		exit(1);
	}
	return (0);
}

void	*routine(void *phil)
{
	t_philo *const philo = (t_philo *)phil;
	// static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

	while (1)
	{
		// pthread_mutex_lock(&lock);
		supervisor(philo);
		if (philo->first == 1)
		{
			pthread_mutex_lock(&philo->my_mutex);
			pthread_mutex_lock(&(*philo->right_fork));
			print_message(FORK, philo->index, philo);
			print_message(FORK, philo->index, philo);
			eat(philo);
		}
		else if (philo->first == 2 && *philo->right_islocked == 0)
		{
			*philo->right_islocked = 1;
			philo->did_i_take_right_fork = 1;
			pthread_mutex_lock(&(*philo->right_fork));
			print_message(FORK, philo->index, philo);
		}
		else
		{
			take_forks(philo);
			if (philo->did_i_take_my_fork == 1 && philo->did_i_take_right_fork == 1)
			{
				if (philo->index == 1)
					printf("my fork = %d,\t right fork = %d\n", philo->did_i_take_my_fork, philo->did_i_take_right_fork);
				eat(philo);
			}
		}
		think(philo);
		// pthread_mutex_lock(&lock);
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
	printf("got to 58\n");
	while (++i < structs->data->num_philos)
	{
		structs->philos[i].last_time_ate = get_time();
		pthread_create(&structs->philos[i].threads, NULL, &routine, &structs->philos[i]);
	}
	pthread_join(monitor_thread, NULL);
	while (i--)
		pthread_join(structs->philos[i].threads, NULL);
	return 1;
}