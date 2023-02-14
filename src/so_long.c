/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:57:16 by diserran          #+#    #+#             */
/*   Updated: 2023/02/14 13:21:09 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	close_program(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	exit(0);
	return (0);
}

static int	check_valid_move(t_vars *vars, int x, int y)
{
	t_line	*line;
	int		height;

	line = vars->map->lines;
	if (vars->pos.y == y)
	{
		height = 0;
		while (height != y)
		{
			printf("altura: %d\n", height);
			line = vars->map->lines->next;
			height++;
		}
		printf("%s\n", line->line);
		if (line->line[x] == 1)
			return (0);
		return (1);
	}
	return (0);
}

static int	key_handler(int keycode, t_vars *vars)
{
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		if (keycode == 13 && check_valid_move(vars, vars->pos.x, (vars->pos.y - 1)))
		{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->img_floor, (vars->pos.x * 64), (vars->pos.y * 64));
				mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->img_player, (vars->pos.x * 64), ((vars->pos.y * 64) - 64));
				vars->pos.y--;
				vars->movs++;
		}
		if (keycode == 1 && check_valid_move(vars, vars->pos.x, (vars->pos.y + 1)))
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->img_floor, (vars->pos.x * 64), (vars->pos.y * 64));
			mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->img_player, (vars->pos.x * 64), ((vars->pos.y * 64) + 64));
			vars->pos.y++;
			vars->movs++;
		}
		if (keycode == 0 && check_valid_move(vars, (vars->pos.x - 1), vars->pos.y ))
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->img_floor, (vars->pos.x * 64), (vars->pos.y * 64));
			mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->img_player, ((vars->pos.x * 64) - 64), (vars->pos.y * 64));
			vars->pos.x--;
			vars->movs++;
		}
		if (keycode == 2 && check_valid_move(vars, (vars->pos.x + 1), vars->pos.y ))
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->img_floor, (vars->pos.x * 64), (vars->pos.y * 64));
			mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->img_player, ((vars->pos.x * 64) + 64), (vars->pos.y * 64));
			vars->pos.x++;
			vars->movs++;
		}
		//printf("You moved %d times\t", vars->movs);
		ft_putstr_fd("You moved ", 1);
		ft_putstr_fd(ft_itoa(vars->movs), 1);
		ft_putstr_fd(" times\n", 1);
	}
	if (keycode == 53)
		close_program(vars);
	return (0);
}

static t_images	*init_sprites(t_vars *vars)
{
	t_images	*sprites;
	int			img_size;

	sprites = (t_images *)malloc(sizeof(t_images));
	sprites->img_floor = mlx_xpm_file_to_image(vars->mlx, "sprites/grass.xpm", &img_size, &img_size);
	sprites->img_wall = mlx_xpm_file_to_image(vars->mlx, "sprites/rock.xpm", &img_size, &img_size);
	sprites->img_player = mlx_xpm_file_to_image(vars->mlx, "sprites/player.xpm", &img_size, &img_size);
	sprites->img_collect = mlx_xpm_file_to_image(vars->mlx, "sprites/collect.xpm", &img_size, &img_size);
	sprites->img_exit = mlx_xpm_file_to_image(vars->mlx, "sprites/exit.xpm", &img_size, &img_size);
	return (sprites);
}

static void	render_map(t_vars *vars, t_line *line)
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
			mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->img_floor, (i * 64), (k * 64));
			if (temp->line[i] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->img_wall, (i * 64), (k * 64));
			if (temp->line[i] == 'P')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->img_player, (i * 64), (k * 64));
				vars->pos.x = i;
				vars->pos.y = k;
			}
			if (temp->line[i] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->img_exit, (i * 64), (k * 64));
			if (temp->line[i] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites->img_collect, (i * 64), (k * 64));
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
	t_vars	*vars;

	if (argc == 2)
	{
		vars = (t_vars *)malloc(sizeof(t_vars));
		if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
			vars->map = map_read(argv[1]);
		else
			error_exit("Error\nMap file extension is not .ber\n");
		map = vars->map;
		vars->mlx = mlx_init();
		if (!vars->mlx)
			return (1);
		vars->win = mlx_new_window(vars->mlx, (map->lines->line_len * 64), (map->y * 64), "./so_long");
		if (!vars->win)
		{
			free(vars->win);
			return (1);
		}
		vars->movs = 0;
		vars->sprites = init_sprites(vars);
		render_map(vars, map->lines);
		mlx_hook(vars->win, 2, 0, key_handler, vars);
		mlx_hook(vars->win, 17, 0, close_program, vars);
		mlx_loop(vars->mlx);
		line = map->lines;
		while (line != NULL)
		{
			free(line);
			line = line->next;
		}
		free(map);
		free(vars);
	}
	else
		error_exit("Not enough arguments!\n");
	return (0);
}
