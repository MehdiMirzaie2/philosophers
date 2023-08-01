#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_data	*data;
	// t_philo	*philo;

	data = NULL;
	// if (ac == 5 || ac == 6)
	if (ac == 5)
	{
		if (check_input(&av[1]) == -1)
			return (found_error("input error"));
		data = malloc(sizeof(t_data));
		if (!data)
			return (0);
		init_data(data, av, ac);
	}
	else
		return (found_error("fix input"));
	// philo->data = data;
	threading(data->philo);
	return (0);
}