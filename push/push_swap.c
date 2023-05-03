/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:21:50 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/03 11:51:33 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stack **a, t_stack **b, int size_stack)
{
	if (size_stack == 2 && !(is_sorted(*a)))
		sa(a);
	else if (size_stack >= 3 && !(is_sorted(*a)))
		sort(a, b, size_stack);
}

void	get_index(t_stack *a, int size_stack)
{
	t_stack	*tmp;
	t_stack	*high;
	int		value;

	while (size_stack > 0)
	{
		tmp = a;
		high = NULL;
		value = INT_MIN;
		while (tmp)
		{
			if (tmp->value == INT_MIN && tmp->index == 0)
				tmp->index = 1;
			if (tmp->value > value && tmp->index == 0)
			{
				value = tmp->value;
				high = tmp;
			}
			else
				tmp = tmp->next;
		}
		if (high != NULL)
			high->index = size_stack;
		size_stack --;
	}
}

void	push_all_in_b(t_stack **a, t_stack **b, int size_stack)
{
	int	pushed;

	pushed = 0;
	while (size_stack - pushed > 2)
	{
		pb(b, a);
		pushed ++;
	}
}
