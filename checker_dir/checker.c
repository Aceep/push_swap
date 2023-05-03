/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:46:57 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/03 16:48:35 by alycgaut         ###   ########.fr       */
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

void	exec_move(t_stack **a, t_stack **b, char *buf)
{
	if (ft_strcmp("sa\n", buf) == 0)
		sa(a);
	else if (ft_strcmp("sb\n", buf) == 0)
		sb(b);
	else if (ft_strcmp("ss\n", buf) == 0)
		ss(a, b);
	else if (ft_strcmp("pa\n", buf) == 0)
		pa(a, b);
	else if (ft_strcmp("pb\n", buf) == 0)
		pb(b, a);
	else if (ft_strcmp("ra\n", buf) == 0)
		ra(a);
	else if (ft_strcmp("rb\n", buf) == 0)
		rb(b);
	else if (ft_strcmp("rr\n", buf) == 0)
		rr(a, b);
	else if (ft_strcmp("rra", buf) == 0)
		rra(a);
	else if (ft_strcmp("rrb", buf) == 0)
		rrb(b);
	else if (ft_strcmp("rrr", buf) == 0)
		rrr(a, b);
}

void	read_move(t_stack *a, t_stack *b)
{
	char	*buf;

	buf = malloc(sizeof(char) * 3);
	while (read(0, buf, 3))
	{
		//ft_printf("%s", buf);
		exec_move(&a, &b, buf);
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
		read_move(a, b);
		if (is_sorted(a))
			return (ft_printf("OK\n"), 0);
		else
			return (ft_printf("KO\n"), 0);
	}
	else if (ac != 1)
		return (error(), EXIT_FAILURE);
	return (0);
}
