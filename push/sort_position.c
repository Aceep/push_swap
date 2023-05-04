/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:46:41 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/04 12:24:44 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack **a, int ca)
{
	while (ca)
	{
		if (ca > 0)
		{
			ra(a);
			ca --;
		}
		else if (ca < 0)
		{
			rra(a);
			ca ++;
		}
	}
}

void	rotate_b(t_stack **b, int cb)
{
	while (cb)
	{
		if (cb > 0)
		{
			rb(b);
			cb --;
		}
		else if (cb < 0)
		{
			rrb(b);
			cb ++;
		}
	}
}

void	lowest_in_first(t_stack **a, int lowest)
{
	while (lowest != 0)
	{
		if (lowest < 0)
		{
			rra(a);
			lowest ++;
		}
		if (lowest > 0)
		{
			ra(a);
			lowest --;
		}
	}
}

void	get_order(t_stack **a)
{
	t_stack	*tmp;
	int		lowest;

	lowest = 0;
	tmp = *a;
	assign_position(a);
	while (tmp)
	{
		if (tmp->index == 1 && tmp->position_in_stack < get_stack_size(*a) / 2)
			lowest = tmp->position_in_stack;
		else if (tmp->index == 1
			&& tmp->position_in_stack >= get_stack_size(*a) / 2)
			lowest += (get_stack_size(*a) - tmp->position_in_stack) * -1;
		tmp = tmp->next;
	}
	lowest_in_first(a, lowest);
}

void	sort(t_stack **a, t_stack **b, int size_stack)
{
	push_all_in_b(a, b, size_stack);
	sort_three(a);
	while (*b)
	{
		get_target_position(a, b);
		cost(a, b);
		cheapest_cost(a, b);
	}
	if (!(is_sorted(*a)))
		get_order(a);
}
