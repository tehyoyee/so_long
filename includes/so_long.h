/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:17:12 by taehykim          #+#    #+#             */
/*   Updated: 2022/08/23 18:17:13 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../mlx/mlx.h"
# include "get_next_line.h"

# define KEY_RELEASE	3
# define KEY_EXIT		17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_img {
	void	*empty;
	void	*exit;
	void	*item;
	void	*player;
	void	*wall;
}			t_img;

typedef struct s_map_info {
	t_img	img;
	void	*mlx;
	void	*win;
	int		pos_h;
	int		pos_w;
	int		height;
	int		width;
	int		steps;
	int		c;
	int		p;
	int		e;
	char	**map;
	char	*map_line;
}			t_map_info;

char	*get_next_line(int fd);
void	init_player_pos(t_map_info *map_info);
void	init_map_info(t_map_info *map_info, int fd);
t_img	set_img(void *mlx);
int		key_press(int keycode, t_map_info *map_info);
void	draw_map(t_map_info map_info);

// move

void	move_a(t_map_info *map_info);
void	move_d(t_map_info *map_info);
void	move_w(t_map_info *map_info);
void	move_s(t_map_info *map_info);
int		exit_game(t_map_info *map_info);

// utils

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);

// error & check

void	exit_error(char *msg);
void	check_arg(int argc, char **argv);
void	check_characters(int c, int p, int e);
void	check_rectangular(char **map);
void	check_surrounded(char **map, int width, int height);
void	check_white_line(char *map_line);

#endif
