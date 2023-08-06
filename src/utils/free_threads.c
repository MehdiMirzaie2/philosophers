/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:46:39 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/08/06 17:50:58 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	free_threads(t_structs *structs)
{
	free(structs->data);
	free(structs->philos);
	free(structs);
}
