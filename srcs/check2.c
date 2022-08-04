#include "so_long.h"

void	check_white_line(char *map_line)
{
	int	i;

	i = 0;
	if (!ft_chrcmp(map_line[0], '\n'))
		exit_error("Map started with a newline\n");
	while (map_line[i + 1])
	{
		if (!ft_strncmp(&map_line[i], "\n\n", 2))
			exit_error("Map has newline at least 1");
		i++;
	}
}