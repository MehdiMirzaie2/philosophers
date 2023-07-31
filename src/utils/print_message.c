#include "../../include/philo.h"

void	print_message(int state, int index)
{
	if (state == EATING)
		printf("%d is eating\n");
	else if (state == SLEEPING)
		printf("%d is sleeping\n");
	else if (state == THINKING)
		printf("%d is thinking\n");
	else if (state == FORK)
		printf("%d has taken a fork\n");
}