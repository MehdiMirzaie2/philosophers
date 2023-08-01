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

static void init_mutex(t_structs *structs)
{
    int		i;
    // t_philo	*philos;

    structs->philos = malloc(sizeof(t_philo) * structs->data->num_philos);
    for (i = 0; i < structs->data->num_philos; i++) {
		structs->philos[i].data = structs->data;
        pthread_mutex_init(&structs->philos[i].mutexes, NULL);
    }

    for (i = 0; i < structs->data->num_philos; i++) {
        structs->philos[i].left_fork = &structs->philos[(i + 1) % structs->data->num_philos].mutexes;
    }
}

void use_av(t_structs *structs, char **av, int ac)
{
	structs->data = malloc(sizeof(t_data));
	structs->data->num_philos = ft_atoi(av[1]);
	structs->data->die_time = ft_atoi(av[2]);
	structs->data->eat_time = ft_atoi(av[3]);
	structs->data->sleep_time = ft_atoi(av[4]);
	structs->data->ntimes_to_eat = -1;
	if (ac == 6)
		structs->data->ntimes_to_eat = ft_atoi(av[5]);
}

// void	init_rlforks(t_data *data)
// {

// }

int	init_data(t_structs *structs, char **av, int ac)
{
	int i;

	i = 0;
	use_av(structs, av, ac);
	init_mutex(structs);
	structs->data->start_time = get_time();
	return (1);
}