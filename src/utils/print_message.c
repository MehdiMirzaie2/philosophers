/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:26:25 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/08/06 22:14:47 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	print_message(int state, int index, t_philo *philo)
{
	u_int64_t				current_time;
	static pthread_mutex_t	lock = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&lock);
	current_time = get_time() - philo->data->start_time;
	if (state == EATING)
		printf("%lld\t%d \033[0;32mis eating\n\033[0;37m", current_time, index);
	else if (state == SLEEPING)
		printf("%lld\t%d \033[0;30mis sleeping\n\033[0;37m", current_time, index);
	else if (state == THINKING)
		printf("%lld\t%d \033[0;36mis thinking\n\033[0;37m", current_time, index);
	else if (state == FORK)
		printf("%lld\t%d \033[0;33mhas taken a fork\n\033[0;37m",
			current_time, index);
	else if (state == DIED)
		printf("%lld\t%d \033[1;31mdied\n\033[0;37m", current_time, index);
	pthread_mutex_unlock(&lock);
}
