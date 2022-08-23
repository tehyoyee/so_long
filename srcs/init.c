/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:44:34 by taehykim          #+#    #+#             */
/*   Updated: 2022/08/23 17:44:35 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_height_width(t_map_info *map_info)
{
	while (map_info->map[0][map_info->width])
		map_info->width++;
	while (map_info->map[map_info->height])
		map_info->height++;
	if (map_info->height > 22 || map_info->width > 41)
		exit_error("Map's too big\n");
}

void	init_player_pos(t_map_info *map_info)
{
	int	x;
	int	y;

	x = 0;
	while (x < map_info->height)
	{
		y = 0;
		while (y < map_info->width)
		{
			if (map_info->map[x][y] == 'P')
			{
				map_info->pos_h = x;
				map_info->pos_w = y;
			}
			y++;
		}
		x++;
	}
}

void	init_cpe(t_map_info *map_info, char c)
{
	if (c == 'C')
		map_info->c++;
	if (c == 'P')
		map_info->p++;
	if (c == 'E')
		map_info->e++;
}

void	check(t_map_info *map_info)
{
	check_characters(map_info->c, map_info->p, map_info->e);
	map_info->map = ft_split(map_info->map_line, '\n');
	check_rectangular(map_info->map);
	get_height_width(map_info);
	check_white_line(map_info->map_line);
	check_surrounded(map_info->map, map_info->width, map_info->height);
	init_player_pos(map_info);
}

void	init_map_info(t_map_info *map_info, int fd)
{
	int		i;
	char	*arr_line;

	arr_line = get_next_line(fd);
	if (!arr_line)
		exit_error("Empty map !\n");
	while (arr_line)
	{
		map_info->map_line = ft_strjoin(map_info->map_line, arr_line);
		free(arr_line);
		arr_line = get_next_line(fd);
	}
	i = 0;
	while (map_info->map_line[i])
	{
		init_cpe(map_info, map_info->map_line[i]);
		i++;
	}
	check(map_info);
}
