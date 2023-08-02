#include "../../include/philo.h"

// static void	init_mutex(t_data *data)
// {
// 	int	i;
// 	t_philo philos[data->num_philos];

// 	i = 0;
// 	// philos = malloc(sizeof(data->philo) * data->num_philos);
// 	pthread_mutex_init(&philos[i].my_mutex, NULL);
// 	while (++i < data->num_philos)
// 	{
// 		memcpy((void *)&philos[i], data->philo, sizeof(t_philo));
// 		pthread_mutex_init(&philos[i].my_mutex, NULL);
// 		philos[i].right_fork = &philos[i - 1].my_mutex;
// 	}
// 	philos[0].right_fork = &philos[i - 1].my_mutex;
// 	data->philo = philos;
// }

static void init_mutex(t_structs *structs)
{
    int		i;
    // t_philo	*philos;

    structs->philos = malloc(sizeof(t_philo) * structs->data->num_philos);
    for (i = 0; i < structs->data->num_philos; i++) {
		structs->philos[i].index = i + 1;
		structs->philos[i].data = structs->data;
		structs->philos[i].im_locked = 0;
        pthread_mutex_init(&structs->philos[i].my_mutex, NULL);
    }

    for (i = 0; i < structs->data->num_philos; i++) {
        structs->philos[i].right_fork = &structs->philos[(i + 1) % structs->data->num_philos].my_mutex;
		structs->philos[i].right_islocked = &structs->philos[(i + 1) % structs->data->num_philos].im_locked;
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

void	lock_even_mutex(t_structs *structs)
{
	int i = 0;
	while (i < structs->data->num_philos)
	{
		if ((structs->philos[i].index % 2 == 0) && (*structs->philos[i].right_islocked == 0))
		{
			// pthread_mutex_lock(&structs->philos[i].my_mutex);
			// pthread_mutex_lock(&(*structs->philos[i].right_fork));
			structs->philos[i].im_locked = 1;
		}
		i++;
	}
}

int	init_data(t_structs *structs, char **av, int ac)
{
	int i;

	i = 0;
	use_av(structs, av, ac);
	init_mutex(structs);
	lock_even_mutex(structs);
	structs->data->start_time = get_time();
	return (1);
}