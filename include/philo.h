# ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
// remove latter
# include <string.h>

# define EATING 0
# define SLEEPING 1
# define THINKING 2
# define FORK 3
# define DIED 4

typedef struct s_philo {
	int				index;
	pthread_t 		threads;
	pthread_mutex_t mutexes;
	int 			is_dead;
	int				num_times_eaten;
	// struct s_data	*data;
	// pthread_mutex_t fork;
	// pthread_mutex_t *right_fork;
	pthread_mutex_t *left_fork;
	int				im_locked;
	int				*left_islocked;
	u_int64_t		last_time_ate;
} t_philo;

typedef struct	s_data {
	// struct s_philo	*philo;
	int				num_philos;
	u_int64_t		die_time;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	int				ntimes_to_eat;
	u_int64_t		start_time;
} t_data;

typedef struct s_structs {
	struct s_philo *philos;
	struct t_data *data;
} t_structs;

// number_of_philosophers time_to_die time_to_eat
// time_to_sleep
// [number_of_times_each_philosopher_must_eat]


// utils
int		check_input(char **values);
int		found_error(char *output);
int		ft_atoi(const char *str);
void	print_message(int state, int index);
u_int64_t	get_time(void);
int	my_usleep(useconds_t sleep_time);

// brain
int	init_data(t_structs *structs, char **av, int ac);
// int		threading(t_philo *philo);
void	eat(t_philo *philo);
int take_forks(t_philo *philo);
void think(t_philo *philo);

#endif