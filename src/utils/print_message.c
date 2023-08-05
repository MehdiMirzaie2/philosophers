/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:26:25 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/08/05 21:28:26 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	print_message(int state, int index, t_philo *philo)
{
	u_int64_t				current_time;
	static pthread_mutex_t	lock = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&lock);
	current_time = get_time();
		current_time = current_time - philo->data->start_time;
	if (state == EATING)
		printf("%lld %d is eating\n", current_time, index);
	else if (state == SLEEPING)
		printf("%lld %d is sleeping\n", current_time, index);
	else if (state == THINKING)
		printf("%lld %d is thinking\n", current_time, index);
	else if (state == FORK)
		printf("%lld %d has taken a fork\n", current_time, index);
	else if (state == DIED)
		printf("%lld %d died\n", current_time, index);
	pthread_mutex_unlock(&lock);
}
