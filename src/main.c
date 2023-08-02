#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_structs *structs;
	// t_data	*data;
	// t_philo	*philo;

	// data = NULL;
	structs = NULL;
	if (ac == 5 || ac == 6)
	// if (ac == 5)
	{
		if (check_input(&av[1]) == -1)
			return (found_error("input error"));
		structs = malloc(sizeof(t_structs));
		if (!structs)
			return (0);
		init_data(structs, av, ac);
	}
	else
		return (found_error("fix input"));
	// structs->data->num_times_eaten = 200;
	threading(structs);
	return (0);
}