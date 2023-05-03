/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:44:09 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/03 11:54:21 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	make_cheapest(t_stack **a, t_stack **b, int ca, int cb)
{
	rotate_a(a, ca);
	rotate_b(b, cb);
	pa(a, b);
}

void	cheapest_cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		cheap;
	int		ca;
	int		cb;

	tmp = *b;
	cheap = INT_MAX;
	while (tmp)
	{
		if (abs(tmp->cost_in_a) + abs(tmp->cost_in_b) < abs(cheap))
		{
			cheap = abs(tmp->cost_in_a) + abs(tmp->cost_in_b);
			ca = tmp->cost_in_a;
			cb = tmp->cost_in_b;
		}
		tmp = tmp->next;
	}
	make_cheapest(a, b, ca, cb);
}

void	cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *a;
	tmp_b = *b;
	size_a = get_stack_size(tmp_a);
	size_b = get_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_in_b = tmp_b->position_in_stack;
		if (tmp_b->position_in_stack > size_b / 2)
			tmp_b->cost_in_b = (size_b - tmp_b->cost_in_b) * -1;
		if (tmp_b->target_position > size_a / 2)
			tmp_b->cost_in_a = (size_a - tmp_b->target_position) * -1;
		else
			tmp_b->cost_in_a = tmp_b->target_position;
		tmp_b = tmp_b->next;
	}
}
