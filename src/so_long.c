/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:57:16 by diserran          #+#    #+#             */
/*   Updated: 2023/02/15 13:55:46 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_valid_move(t_vars *vars, int x, int y)
{
	t_line	*line;

	line = vars->map->lines;
	while (y != line->y)
		line = line->next;
	if (line->line[x] == 'C')
		vars->collected_coins++;
	if (line->line[x] == 'E')
	{
		if (vars->collected_coins != vars->map->collects)
			return (0);
		close_program(vars);
	}
	if (line->line[x] == '1')
		return (0);
	vars->movs++;
	print_movements(vars);
	return (1);
}

static void	move_player(t_vars *vars, int keycode, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, \
	vars->sprites->img_floor, (vars->pos.x * 64), (vars->pos.y * 64));
	if (keycode == 13)
		vars->pos.y--;
	if (keycode == 1)
		vars->pos.y++;
	if (keycode == 0)
		vars->pos.x--;
	if (keycode == 2)
		vars->pos.x++;
	mlx_put_image_to_window(vars->mlx, vars->win, \
	vars->sprites->img_player, x, y);
}

static int	key_handler(int keycode, t_vars *vars)
{
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		if (keycode == 13 && \
		check_valid_move(vars, vars->pos.x, (vars->pos.y - 1)))
			move_player(vars, keycode, \
			(vars->pos.x * 64), ((vars->pos.y * 64) - 64));
		if (keycode == 1 && \
		check_valid_move(vars, vars->pos.x, (vars->pos.y + 1)))
			move_player(vars, keycode, \
			(vars->pos.x * 64), ((vars->pos.y * 64) + 64));
		if (keycode == 0 && \
		check_valid_move(vars, (vars->pos.x - 1), vars->pos.y))
			move_player(vars, keycode, \
			((vars->pos.x * 64) - 64), (vars->pos.y * 64));
		if (keycode == 2 && \
		check_valid_move(vars, (vars->pos.x + 1), vars->pos.y))
			move_player(vars, keycode, \
			((vars->pos.x * 64) + 64), (vars->pos.y * 64));
	}
	if (keycode == 53)
		close_program(vars);
	return (0);
}

static void	so_long(char **argv, t_vars *vars)
{
	t_map	*map;

	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4) == 0)
		vars->map = map_read(argv[1]);
	else
		error_exit("Error\nMap file extension is not .ber\n");
	map = vars->map;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		error_exit("Error!\nProblem loading the minilibx");
	vars->win = mlx_new_window(vars->mlx, \
	(map->lines->line_len * 64), (map->y * 64), "./so_long");
	if (!vars->win)
		error_exit("Error!\nProblem loading the window");
	vars->movs = 0;
	vars->pos = map->initial_pos;
	vars->collected_coins = 0;
	vars->sprites = init_sprites(vars);
	render_map(vars, map->lines);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc == 2)
	{
		vars = (t_vars *)malloc(sizeof(t_vars));
		so_long(argv, vars);
		mlx_hook(vars->win, 2, 0, key_handler, vars);
		mlx_hook(vars->win, 17, 0, close_program, vars);
		mlx_loop(vars->mlx);
	}
	else
		error_exit("Not enough arguments!\n");
	return (0);
}
