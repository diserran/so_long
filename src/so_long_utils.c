/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:38:14 by diserran          #+#    #+#             */
/*   Updated: 2023/02/18 12:57:59 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_exit(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(1);
}

int	close_program(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	exit(0);
	return (0);
}

void	print_movements(t_vars *vars)
{
	ft_putstr_fd("You moved ", 1);
	ft_putstr_fd(ft_itoa(vars->movs), 1);
	ft_putstr_fd(" times\n", 1);
}

int	check_map_extension(char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (extension && ft_strncmp(extension, ".ber", 4) == 0)
		return (1);
	return (0);
}

t_point	get_exit_pos(t_vars *vars)
{
	t_line	*lines;
	t_point	exit;
	int		i;

	lines = vars->map->lines;
	exit.x = 0;
	exit.y = 0;
	while (lines)
	{
		i = 0;
		while (lines->line[i])
		{
			if (lines->line[i] == 'E')
			{
				exit.x = i;
				exit.y = lines->y;
				return (exit);
			}
			i++;
		}
		lines = lines->next;
	}
	return (exit);
}
