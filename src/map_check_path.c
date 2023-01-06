/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:34:07 by diserran          #+#    #+#             */
/*   Updated: 2023/01/06 21:27:03 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	**make_area(t_line *lines, t_point size)
{
	t_line	*current;
	char	**new;
	int		i;

	current = lines;
	new = malloc(sizeof(char *) * size.y);
	i = 0;
	while (i < size.y)
	{
		new[i] = malloc(sizeof(char) * (size.x + 1));
		new[i] = current->line;
		current = current->next;
		i++;
	}
	return (new);
}

static	t_point	get_start_pos(char **map)
{
	t_point	start;

	start.x = 0;
	start.y = 0;
	while (map[start.y])
	{
		if (ft_strchr(map[start.y], 'P'))
		{
			while(map[start.y][start.x] != 'P')
				start.x++;
			return (start);
		}
		start.y++;
	}
	return (start);
}

static void	flood_fill(char **map, t_point start)
{
	if (map[start.y][start.x] == '1')
		return ;
	map[start.y][start.x] = '1';
	flood_fill(map, (t_point){start.x - 1, start.y});
	flood_fill(map, (t_point){start.x + 1, start.y});
	flood_fill(map, (t_point){start.x, start.y - 1});
	flood_fill(map, (t_point){start.x, start.y + 1});
}

void    check_valid_path(t_map *map)
{
	t_point	size;
	t_point	start;
	char	**area;
	int		i;

	size.y = map->y;
	size.x = map->lines->line_len;
	area = make_area(map->lines, size);
	start = get_start_pos(area);
	flood_fill(area, start);
	i = 0;
	while (i < size.y)
	{
		if (ft_strchr(area[i], 'C') || ft_strchr(area[i], 'E'))
			error_exit("Error\nMap must contain a valid path!!!\n");
		i++;
	}
}