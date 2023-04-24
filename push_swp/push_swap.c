#include "../includes/push_swap.h"

int	check_args(char **av)
{
	av ++;
	while (*av)
	{
		while (**av)
		{
			if (!ft_isdigit(**av))
				return (1);
			(*av)++;
		}
		av ++;
	}
	return (0);
}

void	error(void)
{
	ft_printf("Error");
}

int	main(int ac, char **av)
{
	if (ac != 1 && check_args(av) == 0)
		return (ft_printf("OK"), 0);
	else if (ac != 1 && check_args(av) == 1)
		return (error(), 0);
	return (0);
}