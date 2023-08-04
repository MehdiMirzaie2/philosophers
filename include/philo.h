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
# define DROP 5

// typedef enum e_action t_action;

// enum e_action {
// 	E_EATING = 0,
// 	E_SLEEPING = 1,
// 	E_THINKING = 2,
// 	E_FORK = 3,
// 	E_DIED = 4,
// 	E_DROP = 5
// };

typedef struct s_philo {
	struct s_data	*data;
	pthread_t 		threads;
	pthread_mutex_t my_mutex;
	pthread_mutex_t *right_fork;
	int 			is_dead;
	int				index;
	int				my_fork_is_locked;
	int				did_i_take_my_fork;
	int				n_forks_taken;
	// int				*left_islocked;
	int				*right_islocked;
	int				n_times_i_ate;
	// int				*n_times_left_ate;
	// int				*n_times_right_ate;
	u_int64_t		last_time_ate;
} t_philo;

typedef struct	s_data {
	u_int64_t		die_time;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	u_int64_t		start_time;
	int				ntimes_to_eat;
	int				num_philos;
	int				num_times_eaten;
} t_data;

typedef struct s_structs {
	struct s_philo *philos;
	struct s_data *data;
} t_structs;

// number_of_philosophers time_to_die time_to_eat
// time_to_sleep
// [number_of_times_each_philosopher_must_eat]


// utils
int		check_input(char **values);
int		found_error(char *output);
int		ft_atoi(const char *str);
void	print_message(int state, int index, t_philo *philo);
u_int64_t	get_time(void);
int	my_usleep(useconds_t sleep_time);

// brain
int	init_data(t_structs *structs, char **av, int ac);
int	threading(t_structs *structs);
void	eat(t_philo *philo);
void take_forks(t_philo *philo);
void think(t_philo *philo);

#endif