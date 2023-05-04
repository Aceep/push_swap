/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:24:05 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/04 12:33:32 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_highest(t_stack **a)
{
	t_stack	*tmp;
	int		high;

	tmp = *a;
	high = 0;
	while (tmp)
	{
		if (tmp->index > high)
			high = tmp->index;
		tmp = tmp->next;
	}
	return (high);
}

void	sort_three(t_stack **a)
{
	int	high;

	high = find_highest(a);
	if (is_sorted(*a))
		return ;
	if ((*a)->index == high)
		ra(a);
	else if ((*a)->next->index == high)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}
