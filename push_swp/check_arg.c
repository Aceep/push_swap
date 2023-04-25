/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:22:11 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/25 15:45:49 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_args(const char **av)
{
	av ++;
	while (*av)
	{
		if (ft_strlen(*av) > 1)
		{
			if (check_int_size(*av) == 1)
				return (1);
		}
		while (**av)
		{
			if (!ft_isdigit(**av))
				return (1);
			(*av)++;
		}
		av ++;
	}
	return (0);
}

int	check_int_size(const char *av)
{
	int	sign;

	sign = 0;
	if (*av == '-' || *av == '+')
	{
		if ((*av) == '-')
			sign = 1;
		av ++;
	}
	while (*av == '0')
		av ++;
	ft_printf("%s\nsign = %d\nstrlen = %d\nstrcmp = %d\n", av, sign, ft_strlen (av), ft_strncmp(av, "2147483647", 11));
	if (sign == 1 && ft_strlen (av) >= 10 && ft_strncmp(av, "2147483648", 11) > 0)
		return (1);
	else if (sign == 0 && ft_strlen (av) >= 10 && ft_strncmp(av, "2147483647", 11) > 0)
		return (1);
	return (0);
}
