/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:24:52 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/27 16:21:34 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_stack(char *arg)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = ft_atoi(arg);
	new->index = 0;
	new->next = NULL;
	return (new);
}

t_stack	*create_list(char **av)
{
	int			i;
	t_stack		*a;

	i = 1;
	a = NULL;
	while (av[i])
	{
		if (i == 1)
			a = new_stack(av[i]);
		else
			stack_add_back(&a, new_stack(av[i]));
		i ++;
	}
	return (a);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*next;

	if (!new)
		return ;
	if (!stack)
	{
		*stack = new;
		return ;
	}
	next = get_stack_bottom(*stack);
	next->next = new;
}
