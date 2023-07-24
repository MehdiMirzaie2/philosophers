#include "../include/philo.h"

// this program is not using forks like the function, fork is like a chopstick.

int make_philo_specs(t_philo_specs *philo, char **av)
{
	if ((philo->number_of_philo = atoi(av[1])) < 0
			|| (philo->time_to_die = atoi(av[2])) < 0
			|| (philo->time_to_eat = atoi(av[3])) < 0
			|| (philo->time_to_sleep = atoi(av[4])) < 0
			|| (philo->x_times_to_eat = atoi(av[5])) < 0)
			return (-1);
	return (0);
}

int mails = 0;
pthread_mutex_t mutex;

void *routine()
{
	for (int i = 0; i < 10000000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
}

int main(int ac, char **av)
{
	t_philo_specs	*philo;
	pthread_t		thread[ft_atoi(av[1])];
	int				i;

	philo = malloc(sizeof(t_philo_specs));
	if (ac != 6)
		return (-1);
	if (make_philo_specs(philo, av) < 0)
		return (-1);
	i = -1;
	while (++i < philo->number_of_philo)
	{
		if (pthread_create(thread + i, NULL, &routine, NULL) != 0)
		{
			perror("Failed to create thread");
			return (1);
		}
		printf("thread %d has finished execution\n", i);
	}
	i = -1;
	while (++i < philo->number_of_philo)
	{
		if (pthread_join(thread[i], NULL) != 0)
			return (2);
		printf("Thread %d has finished execution\n", i);
	}
	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mails);
	return (0);
}
	// pthread_t thread[], t2;
	// pthread_create(&t1, NULL, &routine, NULL);
	// pthread_create(&t2, NULL, &routine, NULL);
	// pthread_join(t1, NULL);
	// pthread_join(t2, NULL);
