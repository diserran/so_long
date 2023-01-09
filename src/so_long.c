/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:57:16 by diserran          #+#    #+#             */
/*   Updated: 2023/01/09 13:17:46 by diserran         ###   ########.fr       */
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
} */

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
	printf("Cerrando Programa\n");
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_line	*line;
	t_data	img;
	t_vars	vars;

	char	*grass_path = "sprites/grass_big.xpm";
	int		img_size = 64;

	if (argc == 2)
	{
		map = NULL;
		if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
			map = map_read(argv[1]);
		else
			error_exit("Error\nMap file extension is not .ber\n");
		vars.mlx = mlx_init();
		if (!vars.mlx)
			return (1);
		vars.win = mlx_new_window(vars.mlx, (map->lines->line_len * 64), (map->y * 64), "./so_long");
		if (!vars.win)
		{
			free(vars.win);
			return (1);
		}
		//img.img = mlx_new_image(vars.mlx, 800, 450);
		img.img = mlx_xpm_file_to_image(vars.mlx, grass_path, &img_size, &img_size);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		/* for (size_t i = 0; i < 200; i++)
		{
			ft_mlx_pixel_put(&img, i, 50, 0x00FF0000);
			ft_mlx_pixel_put(&img, i, 51, 0x00FF0000);
			ft_mlx_pixel_put(&img, i, 52, 0x00FF0000);
			ft_mlx_pixel_put(&img, i, 53, 0x00FF0000);
		} */
		for (int k = 0; k < 13; k++)
			mlx_put_image_to_window(vars.mlx, vars.win, img.img, (k * 64), 0);
		/* mlx_put_image_to_window(vars.mlx, vars.win, img.img, 16, 0);
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 16);
		mlx_put_image_to_window(vars.mlx, vars.win, img.img, 16, 16); */
		mlx_hook(vars.win, 2, 0, key_handler, &vars);
		mlx_hook(vars.win, 17, 0, close_program, &vars);
		mlx_loop(vars.mlx);
		line = map->lines;
		while (line != NULL)
		{
			free(line);
			line = line->next;
		}
		free(map);
	}
	else
		error_exit("Not enough arguments!\n");
	return (0);
}
