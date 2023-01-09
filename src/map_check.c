/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:26:32 by diserran          #+#    #+#             */
/*   Updated: 2023/01/09 12:03:19 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	save_map(t_line **head, char *line)
{
	t_line	*new_node;
	t_line	*last;

	if (!line)
		return ;
	new_node = (t_line *)malloc(sizeof(t_line));
	last = *head;
	new_node->line = ft_strtrim(line, "\n");
	new_node->line_len = ft_strlen(new_node->line);
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return ;
}

/* El interior de esta función iba inicialmente en
check_requirements, esta fuera para ahorrar lineas */
static t_map	*map_init(t_line *head)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->lines = head;
	map->y = 0; //Comprobar si en mac hace falta declarar el inicio a 0
	map->exit = 0;
	map->collects = 0;
	map->player = 0;
	return (map);
}

static void	map_conditions(t_map *map, t_line *current, int line_len)
{
	int	i;

	i = 0;
	if (map->y == 0 || current->next == NULL)
	{
		i = 0;
		while (current->line[i] == '1')
			i++;
		if (i != line_len)
			error_exit("Error\nMap is not surrounded by walls!!!\n");
	}
	if (current->line_len != line_len)
		error_exit("Error\nMap is not rectangular!!!\n");
	if (current->line[0] != '1' || current->line[line_len - 1] != '1')
		error_exit("Error\nMap is not surrounded by walls!!!\n");
	i = 0;
	while (current->line[i] == '0' || current->line[i] == '1'
		|| current->line[i] == 'C' || current->line[i] == 'E'
		|| current->line[i] == 'P')
		i++;
	if (current->line_len != i)
		error_exit("Error\nCharacters not allowed in the map!!!\n");
}

static void	check_requirements(t_line *current, t_map *map)
{
	int		i;
	int		line_len;

	line_len = current->line_len;
	while (current != NULL)
	{
		map_conditions(map, current, line_len);
		i = 0;
		while (current->line[i])
		{
			if (current->line[i] == 'C')
				map->collects++;
			if (current->line[i] == 'E')
				map->exit++;
			if (current->line[i] == 'P')
				map->player++;
			i++;
		}
		map->y++;
		current = current->next;
	}
	if (map->player != 1 || map->exit != 1 || map->collects < 1)
		error_exit("Error\nIncorrect characters amount!!!\n");
}

t_map	*map_read(char *map_file)
{
	int		fd;
	char	*temp;
	t_line	*lines;
	t_map	*map;

	fd = open(map_file, O_RDONLY);
	temp = "";
	lines = NULL;
	while (temp != NULL)
	{
		temp = get_next_line(fd);
		save_map(&lines, temp);
		free(temp);
	}
	close(fd);
	if (!lines)
		error_exit("Error\nMap can't be empty!!!\n");
	map = map_init(lines);
	check_requirements(lines, map);
	check_valid_path(map);
	return (map);
}
