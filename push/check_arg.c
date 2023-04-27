/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:22:11 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/27 17:04:18 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (check_letters(av[i]) == 1)
			return (1);
		i ++;
	}
	if (same_numbers(av) == 1)
		return (1);
	return (0);
}

int	check_letters(const char *av)
{
	int	sign;
	int	i;

	i = 0;
	sign = 0;
	if (av[i] == '-' || av[i] == '+')
	{
		if ((av[i]) == '-')
			sign = 1;
		i ++;
	}
	while (av[i] == '0')
		i ++;
	if (check_int_size(av, sign) == 1 || !ft_isdigit(av[i]))
		return (1);
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (1);
		i ++;
	}
	return (0);
}

int	check_int_size(const char *av, int sign)
{
	if (sign == 1 && ft_strlen (av) >= 10
		&& ft_strncmp(av, "2147483648", 11) > 0)
		return (1);
	else if (sign == 0 && ft_strlen (av) >= 10
		&& ft_strncmp(av, "2147483647", 11) > 0)
		return (1);
	return (0);
}

int	same_numbers(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (j < i)
		{
			if (strcmp(av[i], av[j]) == 0)
				return (1);
			j ++;
		}
		i ++;
	}
	return (0);
}
