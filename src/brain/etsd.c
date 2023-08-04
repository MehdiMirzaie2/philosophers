#include "../../include/philo.h"

// void take_forks(t_philo *philo)
// {
// 	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// 	pthread_mutex_lock(&lock);
// 	if (philo->index % 2 == 0 && philo->my_fork_is_locked)
// 	{
// 		pthread_mutex_lock(&philo->my_mutex);
// 		pthread_mutex_lock(&(*philo->right_fork));
// 		philo->my_fork_is_locked = 2;
// 	}
// 	else if (philo->index % 2 == 0 && !philo->my_fork_is_locked)
// 		if (!philo->right_islocked)
// 		{
// 			pthread_mutex_lock(&(*philo->right_fork));
// 			philo->my_fork_is_locked = 1;
// 		}
// 	if (philo->index % 2 != 0 && !philo->my_fork_is_locked)
// 	{
// 		if (*philo->right_islocked == 1)
// 			return ;
// 		print_message(FORK, philo->index, philo);
// 		philo->my_fork_is_locked = 1;
// 		pthread_mutex_lock(&(*philo->right_fork));
// 	}
// 	else if	(philo->index % 2 != 0 && philo->my_fork_is_locked)
// 	{
// 		print_message(FORK, philo->index, philo);
// 		philo->my_fork_is_locked = 2;
// 		pthread_mutex_lock(&philo->my_mutex);
// 	}
// 	pthread_mutex_unlock(&lock);
// }

void take_forks(t_philo *philo)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&lock);
	if (philo->index % 2 == 0 && !philo->my_fork_is_locked)
	{
		philo->my_fork_is_locked = 1;
		philo->did_i_take_my_fork = 1;
		print_message(FORK, philo->index, philo);
		pthread_mutex_lock(&philo->my_mutex);
		philo->n_forks_taken = 1;
	}
	if (philo->index % 2 == 0 && philo->did_i_take_my_fork
		&& !(*philo->right_islocked))
	{
		*philo->right_islocked = 1;
		print_message(FORK, philo->index, philo);
		pthread_mutex_lock(&(*philo->right_fork));
		philo->n_forks_taken = 2;
	}
	if (philo->index % 2 != 0 && !(*philo->right_islocked))
	{
		*philo->right_islocked = 1;
		print_message(FORK, philo->index, philo);
		pthread_mutex_lock(&(*philo->right_fork));
		philo->n_forks_taken = 1;
	}
	if (philo->index % 2 != 0 && *philo->right_islocked)
	{
		philo->my_fork_is_locked = 1;
		print_message(FORK, philo->index, philo);
		pthread_mutex_lock(&philo->my_mutex);
		philo->n_forks_taken = 2;
	}
	pthread_mutex_unlock(&lock);
}

void drop_forks(t_philo *philo)
{
	philo->my_fork_is_locked = 0;
	philo->did_i_take_my_fork = 0;
	*philo->right_islocked = 0;
	pthread_mutex_unlock(&philo->my_mutex);
	pthread_mutex_unlock(&(*philo->right_fork));
}

void increase_neaten(t_philo *philo)
{
	pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&lock);
	philo->data->num_times_eaten += 1;
	philo->n_times_i_ate += 1;
	pthread_mutex_unlock(&lock);
}

void	eat(t_philo *philo)
{
	print_message(EATING, philo->index, philo);
	philo->last_time_ate = get_time();
	my_usleep(philo->data->sleep_time);
	increase_neaten(philo);
	drop_forks(philo);
	print_message(SLEEPING, philo->index, philo);
	my_usleep(philo->data->sleep_time);
}

void think(t_philo *philo)
{
	print_message(THINKING, philo->index, philo);
	my_usleep(philo->data->eat_time);
	take_forks(philo);
	if (philo->my_fork_is_locked == 1)
		eat(philo);
}