/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:59:12 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/27 16:22:07 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*end;
	t_stack	*before_end;
	t_stack	*tmp;

	end = get_stack_bottom(*stack);
	before_end = get_stack_before_bottom(*stack);
	tmp = *stack;
	*stack = end;
	before_end->next = NULL;
	(*stack)->next = tmp;
}

void	rra(t_stack **stack)
{
	reverse_rotate(stack);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack)
{
	reverse_rotate(stack);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rra\n");
}
