#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

typedef struct s_philo_specs {
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	x_times_to_eat;
}	t_philo_specs;

typedef struct s_my_philos {
	char *state;
	struct timeval current_time;
	struct my_philo *next;
} t_my_philos;

// typedef struct {
// 	t_philo_specs specs;
// 	pthread_mutex_t	mutex;
// 	pthread_t threads[specs.number_of_philo];
// }

// utils
int	ft_atoi(const char *str);

#endif
