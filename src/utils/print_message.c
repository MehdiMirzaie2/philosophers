#include "../../include/philo.h"

void	print_message(int state, int index, t_philo *philo)
{
	u_int64_t current_time;
	pthread_mutex_t mut;

	pthread_mutex_init(&mut, NULL);
	pthread_mutex_lock(&mut);
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
	pthread_mutex_unlock(&mut);
}