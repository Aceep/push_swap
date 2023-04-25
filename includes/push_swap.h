/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:22:24 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/25 15:37:11 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}t_stack;

//Check arg
int		check_args(const char **av);
int	check_int_size(const char *av);
t_stack	new_stack(char *arg);

//Error
void	error(void);

#endif