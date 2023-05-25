/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:22:11 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/25 17:37:47 by alycgaut         ###   ########.fr       */
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
	int	i;

	i = 0;
	if (check_int_size(av) == 1)
		return (1);
	if ((av[i] == '-' || av[i] == '+') && ft_isdigit(av[i + 1]))
		i ++;
	while (av[i] == '0')
		i++;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (1);
		i ++;
	}
	return (0);
}

int	check_int_size(const char *av)
{
	int	len;

	len = 0;
	if ((av[len] == '-' || av[len] == '+'))
		len ++;
	while (av[len] == '0')
		len ++;
	len = ft_strlen(av) - len;
	if (len > 11)
		return (1);
	if (ft_atol(av) < (long long)INT_MIN)
		return (1);
	else if (ft_atol(av) > (long long)INT_MAX)
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
			if (av[i] && av[j] && ft_atol(av[i]) == ft_atol(av[j]))
				return (1);
			j ++;
		}
		i ++;
	}
	return (0);
}
