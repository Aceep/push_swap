/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:21:50 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/27 16:22:36 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size_stack;

	if (ac != 1 && check_args(av) == 0)
	{
		b = NULL;
		a = create_list(av);
		size_stack = get_stack_size(a);
		ft_printf("%d = size\n", size_stack);
		rra(&a);
		while (size_stack != 1)
		{
			ft_printf("%d\n", a->value);
			a = a->next;
			size_stack --;
		}
		ft_printf("%d\n", a->value);
		if (is_sorted(a) == 1)
			return (free_stack(&a), 0);
		return (free_stack(&a), free_stack(&b), ft_printf("OK\n"), 0);
	}
	else if (ac != 1 && check_args(av) == 1)
		return (error(), 0);
	return (0);
}
