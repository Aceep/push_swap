#include "get_next_line.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char *gnlret;
	int	fd;

	fd = open(av[1], O_RDONLY);
	gnlret = get_next_line(fd);
	while (gnlret)
	{
		printf("%s", gnlret);
		gnlret = get_next_line(fd);
	}
	return (0);
}
