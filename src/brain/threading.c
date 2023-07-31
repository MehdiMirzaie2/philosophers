 #include "../include/philo.h"

void	*trying(void *phil)
{
	int		i;
	t_philo	*philo;

	i = -1;
	philo = (t_philo *)phil;
	while (++i < philo->data->ntimes_to_eat)
	{
		if (philo->index % 2 != 0)
		{
			print_message(SLEEPING, philo[i].index);
			usleep(philo[i].data->sleep_time);
		}
		pthread_mutex_lock(&philo[i].left_fork);
		pthread_mutex_lock(&philo[i].mutexes);
		print_message(EATING, philo[i].index);
		pthread_mutex_unlock(&philo[i].mutexes);
		pthread_mutex_unlock(&philo[i].left_fork);	
	}
	return (phil);
}

int	threading(t_philo *philo)
{
	int	i; 

	i = -1;
	philo->threads = malloc(sizeof(pthread_t) * philo->data->num_philos);
	while (++i < philo->data->num_philos)
		pthread_create(philo[i].threads, NULL, &trying, philo);
	while (i--)
		pthread_join(*philo[i].threads, NULL);
}