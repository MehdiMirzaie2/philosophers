#include "../../include/philo.h"

void	print_message(int state, int index)
{
	if (state == EATING)
		printf("%d is eating\n", index);
	else if (state == SLEEPING)
		printf("%d is sleeping\n", index);
	else if (state == THINKING)
		printf("%d is thinking\n", index);
	else if (state == FORK)
		printf("%d has taken a fork\n", index);
	else if (state == DIED)
		printf("%d died\n", index);
}