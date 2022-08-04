#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../mlx/mlx.h"
#include "get_next_line.h"

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_param{
	int		x;
	int		y;
}				t_param;

typedef struct s_map_info{
	int		height;
	int		width;
	int		c;
	int		p;
	int		e;
	char	**map;
	char	*map_line;
}			t_map_info;

void	init_map_info(t_map_info *map_info, int fd);
char	*get_next_line(int fd);

// utils

size_t	ft_strlen(const char *s);
int	ft_chrcmp(char c1, char c2);
void	ft_putstr(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);

// error & check

void	exit_error(char *msg);
void	check_arg(int argc, char **argv);
void	check_fd(int fd);
void	check_characters(int c, int p, int e);
void	check_rectangular(char **map);
void	check_surrounded(char **map, int width, int height);
void	check_white_line(char *map_line);

#endif