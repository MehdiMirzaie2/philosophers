#include "../../include/philo.h"

// int take_forks(t_philo *philo)
// {
// 	if (pthread_mutex_lock(&philo->mutexes) != 0)
// 		return (1);
// 	print_message(FORK, philo->index, 1);
// 	if (pthread_mutex_lock(&(*philo->left_fork)) != 0)
// 	{
// 		pthread_mutex_unlock(&philo->mutexes);
// 		print_message(DROP, philo->index, 1);
// 		return (1);
// 	}
// 	print_message(FORK, philo->index, 2);
// 	return (0);
// }

int take_forks(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->mutexes) == 0)
	{
		print_message(FORK, philo->index, 1);	
		if (pthread_mutex_lock(&(*philo->left_fork)) != 0)
		{
			pthread_mutex_unlock(&philo->mutexes);
			print_message(DROP, philo->index, 1);
			return (1);
		}
		print_message(FORK, philo->index, 2);
	}
	else
		return (1);
	// if (pthread_mutex_lock(&(*philo->left_fork)) != 0)
	// {
	// 	pthread_mutex_unlock(&philo->mutexes);
	// 	print_message(DROP, philo->index, 1);
	// 	return (1);
	// }
	// print_message(FORK, philo->index, 2);
	return (0);
}

void	eat(t_philo *philo)
{
	u_int64_t change_in_time;

	change_in_time = get_time() - philo->last_time_ate;
	if (change_in_time > philo->data->die_time)
	{
		philo->is_dead = 1;
		exit(EXIT_FAILURE);
	}
	else
	{
		print_message(EATING, philo->index, 1);
		my_usleep(philo->data->sleep_time);
		// philo->num_times_eaten++;
	}
	pthread_mutex_unlock(&philo->mutexes);
	pthread_mutex_unlock(&(*philo->left_fork));
	print_message(SLEEPING, philo->index, 1);
	my_usleep(philo->data->sleep_time);
}

void think(t_philo *philo)
{
	while (take_forks(philo) != 0)
	{
		print_message(THINKING, philo->index, 1);
		continue ;
	}
}