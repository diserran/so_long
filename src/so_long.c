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

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		movs;
}				t_vars;

typedef struct s_images {
	void	*img_floor;
	void	*img_wall;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
}				t_images;

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

static t_images	*init_sprites(t_vars vars)
{
	t_images	*sprites;
	int			img_size;
	/* char		*floor_path = "sprites/grass.xpm";
	char		*wall_path = "sprites/rock.xpm";
	char		*player_path = "sprites/player.xpm";
	char		*collect_path = "sprites/collect.xpm";
	char		*exit_path = "sprites/exit.xpm"; */
	
	sprites = (t_images *)malloc(sizeof(t_images));
	//sprites->img_floor = mlx_xpm_file_to_image(vars.mlx, floor_path, &img_size, &img_size);
	sprites->img_floor = mlx_xpm_file_to_image(vars.mlx, "sprites/grass.xpm", &img_size, &img_size);
	sprites->img_wall = mlx_xpm_file_to_image(vars.mlx, "sprites/rock.xpm", &img_size, &img_size);
	sprites->img_player = mlx_xpm_file_to_image(vars.mlx,"sprites/player.xpm", &img_size, &img_size);
	sprites->img_collect = mlx_xpm_file_to_image(vars.mlx,"sprites/collect.xpm", &img_size, &img_size);
	sprites->img_exit = mlx_xpm_file_to_image(vars.mlx, "sprites/exit.xpm", &img_size, &img_size);
	return (sprites);
}

static void	render_map(t_images *sprites, t_line	*line, t_vars vars)
{

	int		i;
	int		k;
	t_line	*temp;

	temp = line;
	k = 0;
	while (temp != NULL)
	{
		i = 0;
		while (temp->line[i])
		{
			mlx_put_image_to_window(vars.mlx, vars.win, sprites->img_floor, (i * 64), (k * 64));
			if (temp->line[i] == '1')
				mlx_put_image_to_window(vars.mlx, vars.win, sprites->img_wall, (i * 64), (k * 64));
			if (temp->line[i] == 'P')
				mlx_put_image_to_window(vars.mlx, vars.win, sprites->img_player, (i * 64), (k * 64));
			if (temp->line[i] == 'E')
				mlx_put_image_to_window(vars.mlx, vars.win, sprites->img_exit, (i * 64), (k * 64));
			if (temp->line[i] == 'C')
				mlx_put_image_to_window(vars.mlx, vars.win, sprites->img_collect, (i * 64), (k * 64));
			i++;
		}
		k++;
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_line	*line;
	t_vars	vars;
	t_images *sprites;

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
		sprites = init_sprites(vars);
		render_map(sprites, map->lines, vars);
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
