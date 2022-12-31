/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:20:12 by diserran          #+#    #+#             */
/*   Updated: 2022/12/28 14:44:07 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "../src/libft/libft.h"
# include "../src/get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

typedef struct line
{
	char		*line;
	int			line_len;
	int			y;
	struct line	*next;
}	t_line;

typedef struct map
{
	int		collects;
	int		exit;
	int		player;
	int		y;
	t_line	*lines;
}	t_map;

t_map	*map_read(char *map);
void	error_exit(char *msg);

#endif
