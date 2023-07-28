#include "../../include/philo.h"

void	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
		pthread_mutex_init(data->philo->mutexes[i], NULL);
}

int	init_data(t_data *data, char **av, int ac)
{
	data->num_philos = ft_atoi(av[1]);
	data->die_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data->ntimes_to_eat = ft_atoi(av[5]);
	init_mutex(data);
	return (1);
}