/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:46:39 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/08/07 21:23:13 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	free_threads(t_structs *structs)
{
	int	i;

	i = 0;
	while (i < structs->data->num_philos)
	{
		pthread_mutex_destroy(&structs->philos[i].my_mutex);
		i++;
	}
	free(structs->philos);
	free(structs->data);
}
