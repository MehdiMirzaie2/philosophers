/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:26:25 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/08/07 22:09:30 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	print_message(int state, int index, t_philo *philo)
{
	u_int64_t				current_time;
	static pthread_mutex_t	lock = PTHREAD_MUTEX_INITIALIZER;

	if (philo->data->someone_died == 1 || philo->data->reached_n_eat == 1)
			return ;
	pthread_mutex_lock(&lock);
	current_time = get_time() - philo->data->start_time;
	if ((philo->data->someone_died != 1 && philo->data->reached_n_eat != 1) && state == EATING)
		printf("%lld\t%d \033[0;32mis eating\n\033[0;37m", current_time, index);
	else if ((philo->data->someone_died != 1 && philo->data->reached_n_eat != 1) && state == SLEEPING)
		printf("%lld\t%d \033[0;36mis sleeping\n\033[0;37m", current_time, index);
	else if ((philo->data->someone_died != 1 && philo->data->reached_n_eat != 1) && state == THINKING)
		printf("%lld\t%d \033[0;36mis thinking\n\033[0;37m", current_time, index);
	else if ((philo->data->someone_died != 1 && philo->data->reached_n_eat != 1) && state == FORK)
		printf("%lld\t%d \033[0;33mhas taken a fork\n\033[0;37m",
			current_time, index);
	else if ((philo->data->someone_died != 1 && philo->data->reached_n_eat != 1) && state == DIED)
		printf("%lld\t%d \033[1;31mdied\n\033[0;37m", current_time, index);
	pthread_mutex_unlock(&lock);
}
