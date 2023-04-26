/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:24:52 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/26 16:21:32 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


t_stack	new_stack(char *arg)
{
	t_stack	new;

	new.value = ft_atoi(arg);
	new.next = NULL;
	return (new);
}

t_stack	*create_list(char **av)
{
	int	i;
	t_stack	*a;

	i = 2;
	while (av[i])
	{
		
	}
}