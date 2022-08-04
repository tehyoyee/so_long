#include "so_long.h"

void	check_arg(int argc, char **argv)
{
	if (argc != 2)
		exit_error("Type a argument for file name to read the map\n");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 1) != 0)
		exit_error("Map file should be ended with \".ber\"\n");
}

void	check_fd(int fd)
{
	if (fd < 0)
		exit_error("Failed to open file\n");
}

void	check_characters(int c, int p, int e)
{
	if (c < 1 || p < 1 || e < 1)
		exit_error("Map need C, E, P at least 1\n");
}

void	check_rectangular(char **map)
{
	int	i;
	int	width;

	i = 0;
	width = ft_strlen(map[i]);
	while (map[i])
	{
		if (width != ft_strlen(map[i]))
			exit_error("Map is not a rectangular shape\n");
		i++;
	}
}

void	check_surrounded(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (ft_chrcmp(map[0][i], '1'))
			exit_error("Map should be surrounded by the wall ; 1\n");
		if (ft_chrcmp(map[height - 1][i], '1'))
			exit_error("Map should be surrounded by the wall ; 1\n");
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (ft_chrcmp(map[i][0], '1'))
			exit_error("Map should be surrounded by the wall ; 1\n");
		if (ft_chrcmp(map[i][width - 1], '1'))
			exit_error("Map should be surrounded by the wall ; 1\n");
		i++;
	}
}