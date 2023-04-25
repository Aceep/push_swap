/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:21:50 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/25 15:21:51 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	if (ac != 1 && check_args(av) == 0)
		return (ft_printf("OK"), 0);
	else if (ac != 1 && check_args(av) == 1)
		return (error(), 0);
	return (0);
}
