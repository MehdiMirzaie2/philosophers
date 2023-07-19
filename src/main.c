#include "../include/philo.h"

// this program is not using forks like the function, fork is like a chopstick.

int make_philo_specs(t_philo_specs *philo, char **av)
{
	if ((philo->number_of_philo = ft_atoi(av[1]) < 0)
			|| (philo->time_to_die = ft_atoi(av[2]) < 0)
			|| (philo->time_to_eat = ft_atoi(av[3]) < 0)
			|| (philo->time_to_sleep = ft_atoi(av[4]) < 0)
			|| (philo->x_times_to_eat = ft_atoi(av[5]) < 0))
			return (-1);
	return (0);
}

void *routine()
{
	printf("hello from routine\n");
	sleep(3);
	printf("ending thread\n");
	return (NULL);
}

int main(int ac, char **av)
{	
	t_philo_specs	philo;
	pthread_t		thread[ft_atoi(av[1])];
	int				i;

	if (ac == 6)
		if (make_philo_specs(&philo, av) < 0)
			return (-1);
	i = 0;
	
	// pthread_t thread[], t2;
	// pthread_create(&t1, NULL, &routine, NULL);
	// pthread_create(&t2, NULL, &routine, NULL);
	// pthread_join(t1, NULL);
	// pthread_join(t2, NULL);
	return (0);
}