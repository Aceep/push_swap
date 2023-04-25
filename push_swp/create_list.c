/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:24:52 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/25 15:29:14 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	new_stack(char *arg)
{
	t_stack	new;

	new.value = ft_atoi(arg);
	new.next = void ;
	return (new);
}
