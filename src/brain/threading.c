#include "../include/philo.h"

// int	monitor(t_philo *philo)
// {
// 	int	i;
// 	static unsigned int n_finished;

// 	i = 0;
// 	if (i == philo->data->ntimes_to_eat)
// 	{
// 		n_finished += 1;
// 		if (n_finished == philo->data->num_philos)
// 			return (1);
// 	}
// 	return (0);
// }

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
		if (take_forks(philo) == 0)
			eat(philo);
		// else
		// 	think(philo);
	}
	return (NULL);
}

int	threading(t_philo philos[])
{
	int	i;
	// t_philo philos[philo->data->num_philos];

	i = -1;
	// if (philo->data->ntimes_to_eat != -1)
	// 	pthread_create(philo->threads, NULL, &monitor, &philo);

	while (++i < philos->data->num_philos)
	{
		philos[i].index = i;
		philos[i].num_times_eaten = 0;
		philos[i].last_time_ate = philos[i].data->start_time;
		// memcpy((void *)&philos[i], (void *)philo, sizeof(t_philo));
		pthread_create(&philos[i].threads, NULL, &routine, &philos[i]);
	}
	while (i--)
		pthread_join(philos[i].threads, NULL);
	return 1;
}
