/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:46:39 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/08/06 22:46:29 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	free_threads(t_structs *structs)
{
	int	i;

	i = 0;
	while (i < structs->data->num_philos)
	{
		pthread_mutex_destroy(&structs->philos->my_mutex);
		i++;
	}
	free(structs->philos);
	free(structs->data);
	free(structs);
}
