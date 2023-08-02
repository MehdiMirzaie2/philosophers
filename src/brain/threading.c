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
		take_forks(philo);
		if (philo->im_locked)
			eat(philo);
		else
			think(philo);
	}
	return (NULL);
}

int	threading(t_structs *structs)
{
	int	i;

	i = -1;
	// if (philo->data->ntimes_to_eat != -1)
	// 	pthread_create(philo->threads, NULL, &monitor, &philo);
	while (++i < structs->data->num_philos)
	{
		structs->philos[i].index = i;
		structs->philos[i].num_times_eaten = 0;
		structs->philos[i].last_time_ate = structs->data->start_time;
		pthread_create(&structs->philos[i].threads, NULL, &routine, &structs->philos[i]);
	}
	while (i--)
		pthread_join(structs->philos[i].threads, NULL);
	return 1;
}
