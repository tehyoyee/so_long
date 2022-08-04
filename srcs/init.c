#include "so_long.h"

void	get_height_width(t_map_info *map_info)
{
	map_info->height = 0;
	map_info->width = 0;
	while (map_info->map[0][map_info->width])
		map_info->width++;
	while (map_info->map[map_info->height])
		map_info->height++;
}

void	init_map_info(t_map_info *map_info, int fd)
{
	int		i;
	char	*arr_line;
	char	**arr;

	arr_line = get_next_line(fd);
	while (arr_line)
	{
		map_info->map_line = ft_strjoin(map_info->map_line, arr_line);
		free(arr_line);
		arr_line = get_next_line(fd);
	}
	i = 0;
	while (map_info->map_line[i])
	{
		if (ft_strncmp(&map_info->map_line[i], "C", 1) == 0)
			map_info->c++;
		if (ft_strncmp(&map_info->map_line[i], "P", 1) == 0)
			map_info->p++;
		if (ft_strncmp(&map_info->map_line[i], "E", 1) == 0)
			map_info->e++;
		i++;
	}
	check_characters(map_info->c, map_info->p, map_info->e);
	map_info->map = ft_split(map_info->map_line, '\n');
	check_rectangular(map_info->map);
	get_height_width(map_info);
	check_white_line(map_info->map_line);
	check_surrounded(map_info->map, map_info->width, map_info->height);
}
