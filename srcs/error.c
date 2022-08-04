#include "so_long.h"

void	exit_error(char *msg)
{
	ft_putstr("Error\n");
	ft_putstr(msg);
	exit(1);
}
