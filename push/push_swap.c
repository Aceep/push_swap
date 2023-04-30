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
	else if (size_stack >= 3 && !(is_sorted(*a)))
	 	sort(a, b, size_stack);
}

void	get_index(t_stack *a, int size_stack)
{
	t_stack	*tmp;
	t_stack *high;
	int	value;

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
	//int	i;

	pushed = 0;
	while (size_stack - pushed > 2)
	{
		pb(b, a);
		pushed ++;
	}
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
		if (is_sorted(a) == 1)
			return (free_stack(&a), 0);
		get_index(a, size_stack);
		push_swap(&a, &b, size_stack);
		while (a)
		{
			ft_printf("%d,", a->value);
			ft_printf("index = %d\n", a->index);
			ft_printf("position = %d\n", a->position_in_stack);
			a = a->next;
		}
		// ft_printf("%d,", a->value);
		// ft_printf("index = %d\n", a->index);
		// ft_printf("position = %d\n", a->position_in_stack);
		free_stack(&a);
		free_stack(&b);
		return (0);
	}
	else if (ac != 1 && check_args(av) == 1)
		return (error(), 0);
	return (0);
}
