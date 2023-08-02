#include "../../include/philo.h"

void take_forks(t_philo *philo)
{
	if (*philo->right_islocked == 1)
		return ;
	philo->im_locked = 1;
	pthread_mutex_lock(&philo->my_mutex);
	pthread_mutex_lock(&(*philo->right_fork));
}

void drop_forks(t_philo *philo)
{
	philo->im_locked = 0;
	pthread_mutex_unlock(&philo->my_mutex);
	pthread_mutex_unlock(&(*philo->right_fork));
}

void	eat(t_philo *philo)
{
	print_message(EATING, philo->index, philo);
	my_usleep(philo->data->sleep_time);
	drop_forks(philo);
	print_message(SLEEPING, philo->index, philo);
	my_usleep(philo->data->sleep_time);
}

void think(t_philo *philo)
{
	print_message(THINKING, philo->index, philo);
	my_usleep(philo->data->eat_time);
	take_forks(philo);
	if (philo->im_locked == 1)
		eat(philo);
}