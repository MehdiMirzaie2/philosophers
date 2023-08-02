#include "../../include/philo.h"

// int take_forks(t_philo *philo)
// {
// 	if (pthread_mutex_lock(&philo->my_mutex) != 0)
// 		return (1);
// 	print_message(FORK, philo->index, 1);
// 	if (pthread_mutex_lock(&(*philo->right_fork)) != 0)
// 	{
// 		pthread_mutex_unlock(&philo->my_mutex);
// 		print_message(DROP, philo->index, 1);
// 		return (1);
// 	}
// 	print_message(FORK, philo->index, 2);
// 	return (0);
// }

void take_forks(t_philo *philo)
{
	if (*philo->right_islocked == 0)
		return ;
	pthread_mutex_lock(&philo->my_mutex);
	pthread_mutex_lock(&(*philo->right_fork));
	philo->im_locked = 1;
}

void drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->my_mutex);
	pthread_mutex_unlock(&(*philo->right_fork));
	philo->im_locked = 0;
}

void	eat(t_philo *philo)
{
	// u_int64_t change_in_time;

	// change_in_time = get_time() - philo->last_time_ate;
	// if (change_in_time > philo->data->die_time)
	// {
	// 	philo->is_dead = 1;
	// 	exit(EXIT_FAILURE);
	// }
	if (philo->im_locked == 1)
	{
		print_message(EATING, philo->index, 1);
		my_usleep(philo->data->sleep_time);
	}
	drop_forks(philo);
	print_message(SLEEPING, philo->index, 1);
	my_usleep(philo->data->sleep_time);
}

void think(t_philo *philo)
{
	while (philo->im_locked != 0)
	{
		print_message(THINKING, philo->index, 1);
		continue ;
	}
}