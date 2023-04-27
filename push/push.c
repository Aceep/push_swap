/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:40:58 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/27 16:36:49 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (b && a)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
	}
}

void	pa(t_stack **a, t_stack	**b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack	**a)
{
	push(b, a);
	ft_printf("pb\n");
}
