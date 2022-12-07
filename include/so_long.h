/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:20:12 by diserran          #+#    #+#             */
/*   Updated: 2022/12/07 12:25:04 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "../src/libft/libft.h"
# include "../src/get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

typedef struct map
{
	char		*line;
	int			line_len;
	struct map	*next;
}	t_map;

void	*map_checker(char *map);

#endif
