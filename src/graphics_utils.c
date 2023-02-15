/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:00:20 by diserran          #+#    #+#             */
/*   Updated: 2023/02/15 11:13:52 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_images	*init_sprites(t_vars *vars)
{
	t_images	*sprites;
	int			img_size;

	sprites = (t_images *)malloc(sizeof(t_images));
	sprites->img_floor = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/grass.xpm", &img_size, &img_size);
	sprites->img_wall = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/rock.xpm", &img_size, &img_size);
	sprites->img_player = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/player.xpm", &img_size, &img_size);
	sprites->img_collect = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/collect.xpm", &img_size, &img_size);
	sprites->img_exit = mlx_xpm_file_to_image(vars->mlx, \
	"sprites/exit.xpm", &img_size, &img_size);
	if (!sprites->img_floor || !sprites->img_wall || !sprites->img_player || !sprites->img_collect || sprites->img_exit)
		error_exit("Error\nProblem loading the sprites!!!");
	return (sprites);
}

static void	render_map_helper(t_vars *vars, t_line *temp, t_point coords)
{
	mlx_put_image_to_window(vars->mlx, vars->win, \
	vars->sprites->img_floor, (coords.x * 64), (coords.y * 64));
	if (temp->line[coords.x] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->sprites->img_wall, (coords.x * 64), (coords.y * 64));
	if (temp->line[coords.x] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->sprites->img_player, (coords.x * 64), (coords.y * 64));
	if (temp->line[coords.x] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->sprites->img_exit, (coords.x * 64), (coords.y * 64));
	if (temp->line[coords.x] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->sprites->img_collect, (coords.x * 64), (coords.y * 64));
}

void	render_map(t_vars *vars, t_line *line)
{
	t_point	coords;
	t_line	*temp;

	temp = line;
	coords.y = 0;
	while (temp != NULL)
	{
		coords.x = 0;
		while (temp->line[coords.x])
		{
			render_map_helper(vars, temp, coords);
			coords.x++;
		}
		coords.y++;
		temp = temp->next;
	}
}
