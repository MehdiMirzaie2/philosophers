/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:25:34 by mehdimirzai       #+#    #+#             */
/*   Updated: 2023/08/05 21:25:54 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (values[0][0] == '1')
		return (-2);
	while (*values)
	{
		if (ft_strlen(*values) == 1
			&& (*values[0] == '-' || *values[0] == '+'))
			return (-1);
		if (ft_isnum(*values) == -1)
			return (-1);
		++values;
	}
	return (0);
}
