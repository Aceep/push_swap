/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:22:24 by alycgaut          #+#    #+#             */
/*   Updated: 2023/04/26 16:11:22 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}t_stack;

//Check arg
int		check_args(char **av);
int		check_int_size(const char *av, int sign);
int		check_letters(const char *av);

//Create list
t_stack	new_stack(char *arg);
t_stack	*create_list(char **av);

//Error
void	error(void);

#endif