#include "../../include/philo.h"

static void	init_mutex(t_data *data)
{
	int	i;
	t_philo *philos;

	i = 0;
	philos = malloc(sizeof(data->philo) * data->num_philos);
	pthread_mutex_init(&philos[i].mutexes, NULL);
	while (++i < data->num_philos)
	{
		pthread_mutex_init(&philos[i].mutexes, NULL);
		philos[i].left_fork = &philos[i - 1].mutexes;
	}
	philos[0].left_fork = &philos[i - 1].mutexes;
	data->philo = philos;
}
void use_av(t_data *data, char **av, int ac)
{
	data->num_philos = ft_atoi(av[1]);
	data->die_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data->ntimes_to_eat = ft_atoi(av[5]);
}

// void	init_rlforks(t_data *data)
// {

// }

int	init_data(t_data *data, char **av, int ac)
{
	use_av(data, av, ac);
	init_mutex(data);
	// init_rlforks(data);
	return (1);
}