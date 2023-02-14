/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:20:12 by diserran          #+#    #+#             */
/*   Updated: 2023/02/14 11:51:49 by diserran         ###   ########.fr       */
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
	char		*line;
	int			line_len;
	struct line	*next;
}				t_line;

typedef struct map
{
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
}				t_vars;

t_map	*map_read(char *map);
void	error_exit(char *msg);
void	check_valid_path(t_map *head);

#endif
