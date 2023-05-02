#include "../includes/push_swap.h"

void rotate_a(t_stack **a, int ca)
{
    while (ca)
    {
        if (ca > 0)
        {
            ra(a);
            ca --;
        }
        else if (ca < 0)
        {
            rra(a);
            ca ++;
        }
    }
}

void rotate_b(t_stack **b, int cb)
{
    while (cb)
    {
        if (cb > 0)
        {
            rb(b);
            cb --;
        }
        else if (cb < 0)
        {
            rrb(b);
            cb ++;
        }
    }
}

void    make_cheapest(t_stack **a, t_stack **b,  int ca, int cb)
{
    rotate_a(a, ca);
    rotate_b(b, cb);
    pa(a, b);
}
int abs(int nb)
{
    if (nb < 0)
        return (nb *  -1);
    return (nb);
}

void    cheapest_cost(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    int cheap;
    int ca;
    int cb;

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
void    cost(t_stack **a, t_stack **b)
{
    t_stack *tmp_a;
    t_stack *tmp_b;
    int size_a;
    int size_b;

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
            tmp_b->cost_in_a =  (size_a - tmp_b->target_position)  * -1;
        else
            tmp_b->cost_in_a = tmp_b->target_position;
        tmp_b = tmp_b->next;
    }
}

void    get_order(t_stack **a)
{
    t_stack *tmp;
    int lowest;
    lowest = 0;
    tmp = *a;
    assign_position(a);
    while (tmp)
    {
        if (tmp->index == 1 && tmp->position_in_stack < get_stack_size(*a) / 2)
            lowest = tmp->position_in_stack;
        else if (tmp->index == 1 &&  tmp->position_in_stack >= get_stack_size(*a) / 2)
            lowest += (get_stack_size(*a) - tmp->position_in_stack) * -1;
        tmp = tmp->next;
    }
    //ft_printf("low = %d\n", lowest);
    while (lowest != 0)
    {
        if (lowest < 0)
        {   
            rra(a);
            lowest ++;
        }
        if (lowest > 0)
        {
            ra(a);
            lowest --;
        }
    }
}

void	sort(t_stack **a, t_stack **b, int size_stack)
{
	push_all_in_b(a, b, size_stack);
	if (!(is_sorted(*a)))
		sa(a);
   // t_stack *tmp_a = *a;
 //   t_stack *tmp_b = *b;
	while (*b)
	{
		get_target_position(a, b);
        cost(a, b);
        // while (tmp_b)
		// {
		// 	ft_printf("b : %d,", (tmp_b)->value);
		// 	ft_printf("index = %d\n", (tmp_b)->index);
		// 	ft_printf("position = %d\n", (tmp_b)->position_in_stack);
        //     ft_printf("target position = %d\n", (tmp_b)->target_position);
        //     ft_printf("cost a = %d\n", (tmp_b)->cost_in_a);
        //     ft_printf("cost b = %d\n", (tmp_b)->cost_in_b);
		// 	(tmp_b) = (tmp_b)->next;
		// }
        // while (tmp_a)
    	// {
    	// 	ft_printf("a : %d,", (tmp_a)->value);
    	// 	ft_printf("index = %d\n", (tmp_a)->index);
    	// 	ft_printf("position = %d\n", (tmp_a)->position_in_stack);
    	// 	(tmp_a) = (tmp_a)->next;
    	// }
        cheapest_cost(a, b);
	}
    if (!(is_sorted(*a)))
        get_order(a);
}

void	assign_position(t_stack **stack)
{
	int	i;
	t_stack *tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->position_in_stack = i;
		tmp = tmp->next;
		i ++;
	}
}

int position_target(t_stack **a, int idx_b)
{
    t_stack *tmp_a;
    int target_idx;
    int pos_target;

    target_idx = INT_MAX;
    tmp_a = *a;
    pos_target = 0;
    while (tmp_a)
    {
        if (tmp_a->index > idx_b && tmp_a->index < target_idx)
        {
            target_idx = tmp_a->index;
            pos_target = tmp_a->position_in_stack;
        }
        // if (tmp_a->next == NULL && target_idx == INT_MAX)
        // {
        //     target_idx = tmp_a->index;
        //     pos_target = tmp_a->position_in_stack;
        // }
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
    int target_position;
    t_stack *tmp;

    target_position = 0;
	assign_position(a);
	assign_position(b);
    tmp = *b;
    while (tmp)
    {
        target_position = position_target(a, tmp->index);
        tmp->target_position = target_position;
        tmp = tmp->next;
    }
}