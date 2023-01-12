/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:57:16 by diserran          #+#    #+#             */
/*   Updated: 2023/01/12 13:48:21 by diserran         ###   ########.fr       */
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

static int	key_handler(int keycode, t_vars *vars)
{
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		vars->movs++;
		printf("You moved %d times\t", vars->movs);
		printf("Tecla pulsada: %d\n", keycode);
	}
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
	t_data	wall;
	t_data	player;
	t_data	collect;
	t_data	exit;
	t_vars	vars;
	int		i;
	int		k;

	char	*grass_path = "sprites/grass.xpm";
	char	*wall_path = "sprites/rock.xpm";
	char	*player_path = "sprites/player.xpm";
	char	*collect_path = "sprites/collect.xpm";
	char	*exit_path = "sprites/exit.xpm";
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
		vars.movs = 0;
		img.img = mlx_xpm_file_to_image(vars.mlx, grass_path, &img_size, &img_size);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		wall.img = mlx_xpm_file_to_image(vars.mlx, wall_path, &img_size, &img_size);
		wall.addr = mlx_get_data_addr(wall.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		player.img = mlx_xpm_file_to_image(vars.mlx, player_path, &img_size, &img_size);
		player.addr = mlx_get_data_addr(player.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		collect.img = mlx_xpm_file_to_image(vars.mlx, collect_path, &img_size, &img_size);
		collect.addr = mlx_get_data_addr(collect.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		exit.img = mlx_xpm_file_to_image(vars.mlx, exit_path, &img_size, &img_size);
		exit.addr = mlx_get_data_addr(exit.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		line = map->lines;
		k = 0;
		while (line != NULL)
		{
			i = 0;
			while (line->line[i])
			{
				mlx_put_image_to_window(vars.mlx, vars.win, img.img, (i * 64), (k * 64));
				if (line->line[i] == '1')
					mlx_put_image_to_window(vars.mlx, vars.win, wall.img, (i * 64), (k * 64));
				if (line->line[i] == 'P')
					mlx_put_image_to_window(vars.mlx, vars.win, player.img, (i * 64), (k * 64));
				if (line->line[i] == 'E')
					mlx_put_image_to_window(vars.mlx, vars.win, exit.img, (i * 64), (k * 64));
				if (line->line[i] == 'C')
					mlx_put_image_to_window(vars.mlx, vars.win, collect.img, (i * 64), (k * 64));
				i++;
			}
			k++;
			line = line->next;
		}
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
