/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:22:24 by alycgaut          #+#    #+#             */
/*   Updated: 2023/05/04 12:31:51 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"

# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				position_in_stack;
	int				target_position;
	int				cost_in_a;
	int				cost_in_b;
	struct s_stack	*next;
}t_stack;

//Check Arg
int		check_args(char **av);
int		check_int_size(const char *av);
int		check_letters(const char *av);
int		same_numbers(char **av);

//Create List
t_stack	*new_stack(char *arg);
t_stack	*create_list(char **av);
t_stack	*get_stack_bottom(t_stack *stack);
t_stack	*get_stack_before_bottom(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
int		get_stack_size(t_stack	*stack);

//Error
void	error(void);

//Free
void	free_stack(t_stack **a);

//Swap
void	swap(t_stack *stack);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);

//Swap Three
void	sort_three(t_stack **a);
int		find_highest(t_stack **a);

//Rotate
void	rotate(t_stack **stack);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **a, t_stack **b);

//Reverse Rotate
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **a, t_stack **b);

//Push
void	push(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack	**b);
void	pb(t_stack **b, t_stack	**a);

//Sort
void	push_swap(t_stack **a, t_stack **b, int size_stack);
void	sort(t_stack **a, t_stack **b, int size_stack);
void	get_target_position(t_stack **a, t_stack **b);
void	assign_position(t_stack **stack);
void	push_all_in_b(t_stack **a, t_stack **b, int size_stack);
void	get_index(t_stack *a, int size_stack);
void	rotate_a(t_stack **a, int ca);
void	rotate_b(t_stack **b, int cb);
void	lowest_in_first(t_stack **a, int lowest);
void	get_order(t_stack **a);
int		find_highest(t_stack **a);
void	sort_three(t_stack **a);

//Utils
int		abs(int nb);
int		is_sorted(t_stack *stack);

//Cost
void	make_cheapest(t_stack **a, t_stack **b, int ca, int cb);
void	cheapest_cost(t_stack **a, t_stack **b);
void	cost(t_stack **a, t_stack **b);

#endif