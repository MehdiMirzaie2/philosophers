/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:37:01 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/08/06 21:42:15 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
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

typedef struct s_philo {
	struct s_data	*data;
	pthread_t		threads;
	pthread_mutex_t	my_mutex;
	pthread_mutex_t	*right_fork;
	int				is_dead;
	int				index;
	int				my_fork_is_locked;
	int				did_i_take_my_fork;
	int				did_i_take_right_fork;
	int				first;
	int				n_forks_taken;
	int				*right_islocked;
	int				n_times_i_ate;
	u_int64_t		last_time_ate;
}	t_philo;

typedef struct s_data {
	u_int64_t		die_time;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	u_int64_t		start_time;
	int				ntimes_to_eat;
	int				num_philos;
	int				num_times_eaten;
	void			*someone_died;
	void			*reached_n_eat;
}	t_data;

typedef struct s_structs {
	struct s_philo	*philos;
	struct s_data	*data;
}	t_structs;

// utils
int			check_input(char **values);
int			found_error(char *output);
int			ft_atoi(const char *str);
void		print_message(int state, int index, t_philo *philo);
u_int64_t	get_time(void);
int			my_usleep(useconds_t sleep_time);
void		free_threads(t_structs *structs);

// brain
int			init_data(t_structs *structs, char **av, int ac);
int			threading(t_structs *structs);
void		eat(t_philo *philo);
void		take_forks(t_philo *philo);
void		think(t_philo *philo);

#endif