#include "../../include/philo.h"

void	*trying(void *phil)
{
	int		i;
	t_philo	*philo;

	i = -1;
	philo = (t_philo *)phil;
	while (++i < philo->)
}

int	threading(t_philo *philo)
{
	int	i;
	// t_philo	philos[philo->data.num_philos];

	i = -1;
	philo->threads = malloc(sizeof(pthread_t) * philo->data.num_philos);
	while (++i < philo->data.num_philos)
		pthread_create(&philo->threads[i], NULL, &trying, philo);
	while (i--)
		pthread_join(&philo->threads[i], NULL);
}