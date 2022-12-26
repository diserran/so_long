/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:57:16 by diserran          #+#    #+#             */
/*   Updated: 2022/12/26 10:48:24 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		movs;
}				t_vars;

/* static void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static int	key_handler(int keycode, t_vars *vars)
{
	printf("movs %d\t", vars->movs++);
	printf("Tecla pulsada: %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		exit(0);
	}
	return (0);
}

static int	close_program(t_vars *vars)
{
	printf("cerrando programa\n");
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	exit(0);
	return (0);
} */

int	main(int argc, char **argv)
{
	//t_map	*map;
	//t_data	img;
	//t_vars	vars;

	if (argc == 2)
	{
		map_checker(argv[1]);
		/* vars.mlx = mlx_init();
		if (!vars.mlx)
			return (1);
		vars.win = mlx_new_window(vars.mlx, 800, 450, "Hello World!");
		if (!vars.win)
		{
			free(vars.win);
			return (1);
		}
		img.img = mlx_new_image(vars.mlx, 800, 450);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		for (size_t i = 0; i < 200; i++)
		{
			ft_mlx_pixel_put(&img, i, 50, 0x00FF0000);
			ft_mlx_pixel_put(&img, i, 51, 0x00FF0000);
			ft_mlx_pixel_put(&img, i, 52, 0x00FF0000);
			ft_mlx_pixel_put(&img, i, 53, 0x00FF0000);
		}
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
		//mlx_key_hook(vars.win, key_handler, &vars);
		mlx_hook(vars.win, 2, 0, key_handler, &vars);
		mlx_hook(vars.win, 17, 0, close_program, &vars);
		mlx_loop(vars.mlx); */
	}
	else
		write(2, "Not enough arguments!\n", 23);
	return (0);
}
