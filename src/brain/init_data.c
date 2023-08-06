/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:32:03 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/08/06 18:41:21 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	init_mutex_and_set_others(t_structs *structs)
{
	int	i;

	structs->philos = malloc(sizeof(t_philo) * structs->data->num_philos);
	i = 0;
	while (i < structs->data->num_philos)
	{
		structs->philos[i].index = i + 1;
		structs->philos[i].last_time_ate = get_time();
		structs->philos[i].data = structs->data;
		pthread_mutex_init(&structs->philos[i].my_mutex, NULL);
		i++;
	}
	i = 0;
	while (i < structs->data->num_philos)
	{
		structs->philos[i].right_fork = &structs->philos[(i + 1)
			% structs->data->num_philos].my_mutex;
		structs->philos[i].right_islocked = &structs->philos[(i + 1)
			% structs->data->num_philos].my_fork_is_locked;
		i++;
	}
}

void	use_av(t_structs *structs, char **av, int ac)
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
	int	i;

	i = 0;
	while (i < structs->data->num_philos)
	{
		if ((structs->philos[i].index % 2 == 0)
			&& (*structs->philos[i].right_islocked == 0))
		{
			structs->philos[i].first = 1;
			structs->philos[i].my_fork_is_locked = 1;
			structs->philos[i].did_i_take_my_fork = 1;
			*structs->philos[i].right_islocked = 1;
			structs->philos[i].did_i_take_right_fork = 1;
		}
		i++;
	}
}

int	init_data(t_structs *structs, char **av, int ac)
{
	use_av(structs, av, ac);
	init_mutex_and_set_others(structs);
	lock_even_mutex(structs);
	structs->data->start_time = get_time();
	return (1);
}
