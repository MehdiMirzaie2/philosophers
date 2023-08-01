#include "../../include/philo.h"

// static void	init_mutex(t_data *data)
// {
// 	int	i;
// 	t_philo philos[data->num_philos];

// 	i = 0;
// 	// philos = malloc(sizeof(data->philo) * data->num_philos);
// 	pthread_mutex_init(&philos[i].mutexes, NULL);
// 	while (++i < data->num_philos)
// 	{
// 		memcpy((void *)&philos[i], data->philo, sizeof(t_philo));
// 		pthread_mutex_init(&philos[i].mutexes, NULL);
// 		philos[i].left_fork = &philos[i - 1].mutexes;
// 	}
// 	philos[0].left_fork = &philos[i - 1].mutexes;
// 	data->philo = philos;
// }

// static void init_mutex(t_data *data) {
//     int i;
//     t_philo *philos;

//     philos = malloc(sizeof(t_philo) * data->num_philos);

//     for (i = 0; i < data->num_philos; i++) {
//         pthread_mutex_init(&philos[i].mutexes, NULL);
//     }

//     for (i = 0; i < data->num_philos; i++) {
//         philos[i].left_fork = &philos[(i + 1) % data->num_philos].mutexes;
//     }

//     data->philo = philos;
// }

void use_av(t_data *data, char **av, int ac)
{
	data->num_philos = ft_atoi(av[1]);
	data->die_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data->ntimes_to_eat = ft_atoi(av[5]);
	else
	{
		data->ntimes_to_eat = -1;
	}

}

// void	init_rlforks(t_data *data)
// {

// }

int	init_data(t_structs *structs, char **av, int ac)
{
	int i;

	i = 0;
	use_av(&structs->data, av, ac);
	// init_mutex(data);
	// data->start_time = get_time();
	// // data->philo->is_dead = 0;
	// while (i++ < data->num_philos)
	// 	data->philo[i].data = data;
	return (1);
}