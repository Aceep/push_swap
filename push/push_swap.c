/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:21:50 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/27 17:43:15 by alycgaut         ###   ########.fr       */
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

void	push_swap(t_stack **a, t_stack **b, int size_stack)
{
	if (size_stack == 2 && !(is_sorted(*a)))
		sa(a);
	else if (size_stack)
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
		//ft_printf("%d = size\n", size_stack);
		if (is_sorted(a) == 1)
			return (free_stack(&a), 0);
		push_swap(&a, &b, size_stack);
		while (a != get_stack_bottom(a))
		{
			ft_printf("%d\n", a->value);
			a = a->next;
		}
		ft_printf("%d\n", a->value);
		free_stack(&a);
		free_stack(&b);
		return (0);
	}
	else if (ac != 1 && check_args(av) == 1)
		return (error(), 0);
	return (0);
}
