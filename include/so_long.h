/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:20:12 by diserran          #+#    #+#             */
/*   Updated: 2023/02/18 12:45:59 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "../src/libft/libft.h"
# include "../src/get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct line
{
	int			y;
	char		*line;
	int			line_len;
	struct line	*next;
}				t_line;

typedef struct map
{
	t_point	initial_pos;
	t_point	exit_pos;
	int		collects;
	int		exit;
	int		player;
	int		y;
	t_line	*lines;
}				t_map;

typedef struct s_images {
	void	*img_floor;
	void	*img_wall;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
}				t_images;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_map		*map;
	t_images	*sprites;
	t_point		pos;
	int			movs;
	int			collected_coins;
}				t_vars;

void		error_exit(char *msg);
int			close_program(t_vars *vars);
void		print_movements(t_vars *vars);
int			check_map_extension(char *filename);
t_point		get_exit_pos(t_vars *vars);
t_images	*init_sprites(t_vars *vars);
void		render_map(t_vars *vars, t_line *line);
t_map		*map_read(int fd);
void		check_valid_path(t_map *head);

#endif
