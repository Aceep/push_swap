 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:46:03 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/03 12:03:09 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_position(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->position_in_stack = i;
		tmp = tmp->next;
		i ++;
	}
}

int	position_target(t_stack **a, int idx_b, int target_idx, int pos_target)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > idx_b && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			pos_target = tmp_a->position_in_stack;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (pos_target);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			pos_target = tmp_a->position_in_stack;
		}
		tmp_a = tmp_a->next;
	}
	return (pos_target);
}

void	get_target_position(t_stack **a, t_stack **b)
{
	int		target_position;
	t_stack	*tmp;

	target_position = 0;
	assign_position(a);
	assign_position(b);
	tmp = *b;
	while (tmp)
	{
		target_position = position_target(a, tmp->index, INT_MAX, 0);
		tmp->target_position = target_position;
		tmp = tmp->next;
	}
}
