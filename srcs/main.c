#include "so_long.h"
/*
int	main(void)
{
	
	//	창띄우기

	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	
	void	*mlx_win;

	void	*img;
	void	*mlx;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img = mlx_new_image(mlx, 1920, 1080);
	mlx_loop(mlx);
}

*/

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

void	show_map_info(t_map_info map_info)
{
	printf("\n===== SHOW MAP INFO =====\n\n");
	printf("height = %d\n", map_info.height);
	printf("width = %d\n", map_info.width);
	printf("c = %d\n", map_info.c);
	printf("p = %d\n", map_info.p);
	printf("e = %d\n", map_info.e);
	printf("\n===== map_line ===== \n%s\n===== map_line =====\n\n", map_info.map_line);

	printf("\n===== map ===== \n");
	for (int i = 0; map_info.map[i]; i++)
		printf("%s\n", map_info.map[i]);
	printf("===== map ===== \n\n");
}

int	main(int argc, char *argv[])
{
	t_map_info	map_info;
	t_param		param;
	void		*mlx;
	void		*win;
	int			fd;
	char		*arr;

	check_arg(argc, argv);
	fd = open(argv[1], O_RDONLY);
	check_fd(fd);
	init_map_info(&map_info, fd);
	show_map_info(map_info);

	system("leaks so_long");

	// param_init(&param);
	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 500, 500, "mlx_project");
	// mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
	// mlx_loop(mlx);
}
/*
0x00FF0000 는 16진법 ARGB(0,255,0,0)를 표현한 것입니다. 
*/