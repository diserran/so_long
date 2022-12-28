/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:26:32 by diserran          #+#    #+#             */
/*   Updated: 2022/12/28 15:06:26 by diserran         ###   ########.fr       */
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

static t_map	*check_requirements(t_line **head)
{
	t_line	*current;
	t_map	*map;
	int		i;
	int		line_len;

	current = *head;
	line_len = current->line_len;
	map = (t_map *)malloc(sizeof(t_map));
	map->lines = current;
	while (current != NULL)
	{
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
		while (current->line[i] == '0' || current->line[i] == '1' || current->line[i] == 'C' || current->line[i] == 'E' || current->line[i] == 'P')
			i++;
		if (current->line_len != i)
			error_exit("Error\nCharacters not allowed in the map!!!\n");
		map->y++;
		current = current->next;
	}
	return (map);
}

t_map	*map_checker(char *map_file)
{
	t_line	*lines;
	char	*temp;
	int		fd;

	if (ft_strnstr(map_file, ".ber", ft_strlen(map_file)))
	{
		fd = open(map_file, O_RDONLY);
		temp = ft_calloc(1,1);
		lines = NULL;
		while (temp != NULL)
		{
			temp = get_next_line(fd);
			save_map(&lines, temp);
		}
		free(temp);
		close(fd);
		return (check_requirements(&lines));
	}
	else
		error_exit("Error\nMap file extension is not .ber\n");
	return (NULL);
}
