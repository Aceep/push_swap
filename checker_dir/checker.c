/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:46:57 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/04 15:11:14 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	exec_move(t_stack **a, t_stack **b, char *buf)
{
	if (ft_strcmp("sa\n", buf) == 0)
		return (swap(*a), 0);
	else if (ft_strcmp("sb\n", buf) == 0)
		return (swap(*b), 0);
	else if (ft_strcmp("ss\n", buf) == 0)
		return (swap(*a), swap(*b), 0);
	else if (ft_strcmp("pa\n", buf) == 0)
		return (push(a, b), 0);
	else if (ft_strcmp("pb\n", buf) == 0)
		return (push(b, a), 0);
	else if (ft_strcmp("ra\n", buf) == 0)
		return (rotate(a), 0);
	else if (ft_strcmp("rb\n", buf) == 0)
		return (rotate(b), 0);
	else if (ft_strcmp("rr\n", buf) == 0)
		return (rotate(a), rotate(b), 0);
	else if (ft_strcmp("rra\n", buf) == 0)
		return (reverse_rotate(a), 0);
	else if (ft_strcmp("rrb\n", buf) == 0)
		return (reverse_rotate(b), 0);
	else if (ft_strcmp("rrr\n", buf) == 0)
		return (reverse_rotate(a), reverse_rotate(b), 0);
	return (0);
}

void	read_move(t_stack **a, t_stack **b)
{
	char	*gnl_return;

	gnl_return = get_next_line(0);
	while (gnl_return)
	{
		exec_move(a, b, gnl_return);
		gnl_return = get_next_line(0);
	}
	close(0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac != 1 && check_args(av) == 0)
	{
		b = NULL;
		a = create_list(av);
		read_move(&a, &b);
		if (is_sorted(a) && b == NULL)
			return (ft_printf("OK\n"), 0);
		else
			return (ft_printf("KO\n"), 0);
	}
	else if (ac != 1)
		return (error(), EXIT_FAILURE);
	return (0);
}
