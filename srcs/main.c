/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:44:04 by taehykim          #+#    #+#             */
/*   Updated: 2022/08/23 17:44:05 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_fd(int fd)
{
	if (fd < 0)
		exit_error("Failed to open file\n");
}

int	main(int argc, char *argv[])
{
	t_map_info	map_info;
	int			fd;

	check_arg(argc, argv);
	fd = open(argv[1], O_RDONLY);
	check_fd(fd);
	init_map_info(&map_info, fd);
	map_info.mlx = mlx_init();
	map_info.win = mlx_new_window(map_info.mlx, \
	map_info.width * 64, map_info.height * 64, "taehyeong's game");
	map_info.img = set_img(map_info.mlx);
	draw_map(map_info);
	mlx_hook(map_info.win, KEY_RELEASE, 0, &key_press, &map_info);
	mlx_hook(map_info.win, KEY_EXIT, 0, &exit_game, &map_info);
	mlx_loop(map_info.mlx);
	ft_free_final(&map_info);
}
