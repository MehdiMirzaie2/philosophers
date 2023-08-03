#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_structs *structs;
	int ret_val;

	structs = NULL;
	if (ac == 5 || ac == 6)
	{
		if ((ret_val = (check_input(&av[1]))) == -1)
			return (found_error("input error"));
		else if (ret_val == -2)
			return (printf("0 1 died\n"));
		structs = malloc(sizeof(t_structs));
		if (!structs)
			return (0);
		init_data(structs, av, ac);
	}
	else
		return (found_error("fix input: should be between 5 and 6"));
	threading(structs);
	return (0);
}