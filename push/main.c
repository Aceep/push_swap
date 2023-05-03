/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:40:57 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/03 11:52:09 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

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
		if (is_sorted(a) == 1)
			return (free_stack(&a), 0);
		get_index(a, size_stack);
		push_swap(&a, &b, size_stack);
		//  
		free_stack(&a);
		free_stack(&b);
		return (0);
	}
	else if (ac != 1 && check_args(av) == 1)
		return (error(), EXIT_FAILURE);
	return (0);
}
