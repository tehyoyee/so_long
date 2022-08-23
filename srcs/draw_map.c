/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:44:11 by taehykim          #+#    #+#             */
/*   Updated: 2022/08/23 17:44:12 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map_2(t_map_info map_info, int w, int h)
{
	if (map_info.map[h][w] == '1')
		mlx_put_image_to_window(map_info.mlx, map_info.win, \
			map_info.img.wall, 64 * w, 64 * h);
	else if (map_info.map[h][w] == '0')
		mlx_put_image_to_window(map_info.mlx, map_info.win, \
			map_info.img.empty, 64 * w, 64 * h);
	else if (map_info.map[h][w] == 'C')
	{
		mlx_put_image_to_window(map_info.mlx, map_info.win, \
			map_info.img.empty, 64 * w, 64 * h);
		mlx_put_image_to_window(map_info.mlx, map_info.win, \
			map_info.img.item, 64 * w, 64 * h);
	}			
	else if (map_info.map[h][w] == 'E')
		mlx_put_image_to_window(map_info.mlx, map_info.win, \
			map_info.img.exit, 64 * w, 64 * h);
	else if (map_info.map[h][w] == 'P')
	{
		mlx_put_image_to_window(map_info.mlx, map_info.win, \
			map_info.img.empty, 64 * w, 64 * h);
		mlx_put_image_to_window(map_info.mlx, map_info.win, \
			map_info.img.player, 64 * w, 64 * h);
	}
}

void	draw_map(t_map_info map_info)
{
	int	w;
	int	h;

	w = 0;
	while (w < map_info.width)
	{
		h = 0;
		while (h < map_info.height)
		{
			draw_map_2(map_info, w, h);
			h++;
		}
		w++;
	}
}

t_img	set_img(void *mlx)
{
	t_img	img;
	int		img_width;
	int		img_height;

	img.empty = mlx_xpm_file_to_image \
		(mlx, "./images/empty.xpm", &img_width, &img_height);
	img.exit = mlx_xpm_file_to_image \
		(mlx, "./images/exit.xpm", &img_width, &img_height);
	img.item = mlx_xpm_file_to_image \
		(mlx, "./images/item.xpm", &img_width, &img_height);
	img.player = mlx_xpm_file_to_image \
		(mlx, "./images/player.xpm", &img_width, &img_height);
	img.wall = mlx_xpm_file_to_image \
		(mlx, "./images/wall.xpm", &img_width, &img_height);
	return (img);
}
