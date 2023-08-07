/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:26:25 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/08/07 22:49:24 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	print_message(int state, int index, t_philo *philo)
{
	u_int64_t				current_time;
	static pthread_mutex_t	lock = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&lock);
	current_time = get_time() - philo->data->start_time;
	if ((philo->data->someone_died != 1 && philo->data->reached_n_eat != 1)
		&& state == EATING)
		printf("%lld\t%d %sis eating\n%s", current_time, index, CYAN, RESET);
	else if ((philo->data->someone_died != 1 && philo->data->reached_n_eat != 1)
		&& state == SLEEPING)
		printf("%lld\t%d %sis sleeping\n%s", current_time, index, YELLOW, RESET);
	else if ((philo->data->someone_died != 1 && philo->data->reached_n_eat != 1)
		&& state == THINKING)
		printf("%lld\t%d%s is thinking\n%s", current_time, index, GREEN, RESET);
	else if ((philo->data->someone_died != 1 && philo->data->reached_n_eat != 1)
		&& state == FORK)
		printf("%lld\t%d%s has taken a fork\n%s",
			current_time, index, PURPLE, RESET);
	else if ((philo->data->someone_died != 1 && philo->data->reached_n_eat != 1)
		&& state == DIED)
		printf("%lld\t%d%s died\n%s", current_time, index, RED, RESET);
	pthread_mutex_unlock(&lock);
}
