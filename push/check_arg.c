/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceep <aceep@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:22:11 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/24 21:40:47 by aceep            ###   ########.fr       */
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
	// sign = 0;

	// while (av[i] == '0' && ft_strlen(av) != 1)
	// 	i ++;
	if (check_int_size(av) == 1)
		return (1);
	if ((av[i] == '-' || av[i] == '+') && ft_isdigit(av[i + 1]))
		i ++;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (1);
		i ++;
	}
	// if (ft_atol(av) == 0)
	// 	return (0);
	return (0);
}

int	check_int_size(const char *av)
{
	char	*i;

	i = ft_strdup(av);
	while (*i == '0')
		i ++;
	if (ft_strlen(i) > 11)
		return (free(i), 1);
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
