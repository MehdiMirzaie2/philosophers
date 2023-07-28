# ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

# define EATING 0
# define SLEEPING 1
# define THINKING 2

typedef struct s_philo {
	pthread_t 		*threads;
	pthread_mutex_t mutexes;
	pthread_mutex_t fork;
	int 			is_dead;
	int				num_times_eaten;
	struct s_data	data;
} t_philo;

typedef struct	s_data {
	struct s_philo	*philo;
	int				num_philos;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				ntimes_to_eat;
} t_data;

// number_of_philosophers time_to_die time_to_eat
// time_to_sleep
// [number_of_times_each_philosopher_must_eat]


// utils
int		check_input(char **values);
int		found_error(char *output);
int		ft_atoi(const char *str);

// brain
int		init_data(t_data *data, char **av, int ac);
int		threading(t_philo *philo);

#endif