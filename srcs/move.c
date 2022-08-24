/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:09:56 by taehykim          #+#    #+#             */
/*   Updated: 2022/08/23 18:09:57 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_map_info *map_info)
{
	printf("steps : %d\n", map_info->steps + 1);
	printf("Mission Complete !\n");
	mlx_destroy_window(map_info->mlx, map_info->win);
	ft_free_final(map_info);
	exit(0);
}

void	move_w(t_map_info *map_info)
{
	int	h;
	int	w;

	w = map_info->pos_w;
	h = map_info->pos_h;
	if (map_info->map[h - 1][w] == '1')
		return ;
	if (map_info->map[h - 1][w] == 'E')
	{
		if (map_info->c != 0)
			return ;
		end_game(map_info);
	}
	map_info->steps++;
	if (map_info->map[h - 1][w] == 'C')
		map_info->c--;
	map_info->map[h][w] = '0';
	map_info->map[h - 1][w] = '0';
	draw_map(*map_info);
	map_info->map[h - 1][w] = 'P';
	map_info->pos_h--;
	draw_map(*map_info);
	printf("steps : %d\n", map_info->steps);
}

void	move_s(t_map_info *map_info)
{
	int	h;
	int	w;

	w = map_info->pos_w;
	h = map_info->pos_h;
	if (map_info->map[h + 1][w] == '1')
		return ;
	if (map_info->map[h + 1][w] == 'E')
	{
		if (map_info->c != 0)
			return ;
		end_game(map_info);
	}
	map_info->steps++;
	if (map_info->map[h + 1][w] == 'C')
		map_info->c--;
	map_info->map[h + 1][w] = '0';
	draw_map(*map_info);
	map_info->map[h + 1][w] = 'P';
	map_info->map[h][w] = '0';
	map_info->pos_h++;
	draw_map(*map_info);
	printf("steps : %d\n", map_info->steps);
}

void	move_a(t_map_info *map_info)
{
	int	h;
	int	w;

	w = map_info->pos_w;
	h = map_info->pos_h;
	if (map_info->map[h][w - 1] == '1')
		return ;
	if (map_info->map[h][w - 1] == 'E')
	{
		if (map_info->c != 0)
			return ;
		end_game(map_info);
	}
	if (map_info->map[h][w - 1] == 'C')
		map_info->c--;
	map_info->steps++;
	map_info->map[h][w - 1] = '0';
	draw_map(*map_info);
	map_info->map[h][w - 1] = 'P';
	map_info->map[h][w] = '0';
	map_info->pos_w--;
	draw_map(*map_info);
	printf("steps : %d\n", map_info->steps);
}

void	move_d(t_map_info *map_info)
{
	int	h;
	int	w;

	w = map_info->pos_w;
	h = map_info->pos_h;
	if (map_info->map[h][w + 1] == '1')
		return ;
	if (map_info->map[h][w + 1] == 'E')
	{
		if (map_info->c != 0)
			return ;
		end_game(map_info);
	}
	if (map_info->map[h][w + 1] == 'C')
		map_info->c--;
	map_info->steps++;
	map_info->map[h][w + 1] = '0';
	draw_map(*map_info);
	map_info->map[h][w + 1] = 'P';
	map_info->map[h][w] = '0';
	map_info->pos_w++;
	draw_map(*map_info);
	printf("steps : %d\n", map_info->steps);
}
