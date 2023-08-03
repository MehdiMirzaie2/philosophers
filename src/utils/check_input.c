#include "../../include/philo.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_isnum(char *data)
{
	int	flag;

	flag = 0;
	while (*data)
	{
		if (!(*data >= '0' && *data <= '9') && (*data != '-' && *data != '+'))
			return (-1);
		if (*data == '-' || *data == '+')
			flag++;
		++data;
	}
	if (flag > 1)
		return (-1);
	return (0);
}

int	check_input(char **values)
{
	while (*values)
	{
		if (values[0][0] == '1')
			return (-2);
		if (ft_strlen(*values) == 1
			&& (*values[0] == '-' || *values[0] == '+'))
			return (-1);
		if (ft_isnum(*values) == -1)
			return (-1);
		++values;
	}
	return (0);
}
