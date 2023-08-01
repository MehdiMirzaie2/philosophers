#include "../../include/philo.h"

u_int64_t	get_time(void)
{
	struct timeval current_time;
	u_int64_t	micro_seconds;

	gettimeofday(&current_time, NULL);
	micro_seconds = (current_time.tv_sec * (u_int64_t)1000) + (current_time.tv_usec / 1000);
	return (micro_seconds);
}

int	my_usleep(useconds_t sleep_time)
{
	u_int64_t iterator;

	iterator = get_time();
	while ((get_time() - iterator) < sleep_time)
		usleep(sleep_time / 10);
	return (0);
}