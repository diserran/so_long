/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:26:32 by diserran          #+#    #+#             */
/*   Updated: 2022/12/26 13:04:38 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* static int	read_map(int fd, t_map *head)
{
	int		i;
	size_t	line_len;
	t_map	*last_line;

	i = 0;
	line_len = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line)
		{
			line_len = ft_strlen(line);
			if (line[line_len - 1] == '\n')
				line_len--;

			map[i] = (char *) malloc(sizeof(char) * line_len);
			map[i] = ft_memcpy(map[i], line, line_len);
			free(line);
		}
		i++;
	}
	return (0);
} */

/* static int	is_rectangular(char **map)
{
	int		i;
	size_t	initial_len;

	i = 0;
	initial_len = ft_strlen(map[0]);
	while (map[i])
	{
		if (initial_len != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
} */

/* static int	read_map(int fd, t_map *head)
{
	int		i;
	//size_t	line_len;
	t_map	*new_line;
	t_map	*current;
	//t_map	*tail = &head->next;

	i = 1;
	//line_len = 0;
	current = head;
	printf("Mapa %d direccion %p\n", i, current);
	printf("Mapa %d linea %s\n", i, current->line);
	printf("Mapa %d siguiente %p\n", i, current->next);
	printf("----------------------------------------------\n");
	while (current->line != NULL)
	{
		new_line = (t_map *)malloc(sizeof(t_map));
		new_line->line = get_next_line(fd);
		current = new_line;
		if (new_line->line)
		{
			new_line->line_len = ft_strlen(new_line->line);
			if (new_line->line[new_line->line_len - 1] == '\n')
				new_line->line_len--;
			new_line->line = (char *) malloc(sizeof(char) * new_line->line_len);
			new_line->line = ft_memcpy(new_line->line, new_line->line, new_line->line_len);
		}
		i++;
		printf("Mapa %d direccion %p\n", i, current);
		printf("Mapa %d linea %s\n", i, current->line);
		printf("Mapa %d siguiente %p\n", i, current->next);
		printf("----------------------------------------------\n");
	}
	return (0);
} */

static void	save_map(t_map **head, char *line)
{
	t_map	*new_node;
	t_map	*last;

	if (!line)
		return ;
	new_node = (t_map *)malloc(sizeof(t_map));
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

static void	check_requirements(t_map **head)
{
	t_map	*current;
	int		i;
	char	*chars;
	int		j;

	current = *head;
	i = 0;
	chars = "01CEP";
	while (current != NULL)
	{
		while (current->line[i])
		{
			j = 0;
			/* while (chars[j])
			{
				printf("line: %c\n", current->line[i]);
				printf("char: %c\n", chars[j]);
				if (current->line[i] != '0' || current->line[i] != '1' || current->line[i] != 'C' || current->line[i] != 'E' current->line[i] != 'P' )
					return (ft_putstr_fd("Error\nInvalid characters in map!\n", STDERR_FILENO));
				j++;
			} */
			if (current->line[i] != '0' && current->line[i] != '1' && current->line[i] != 'C' && current->line[i] != 'E' && current->line[i] != 'P' )
			{
				printf("error char %c\n", current->line[i]);
				return (ft_putstr_fd("Error\nInvalid characters in map!\n", STDERR_FILENO));
			}
			i++;
		}
		current = current->next;
	}
}

/* int	get_dimensions(char *map_file, int	**size)
{
	int		fd;
	int		x;
	int		y;
	char	*temp;

	fd = open(map_file, O_RDONLY);
	y = 1;
	temp = get_next_line(fd);
	x = ft_strlen(temp) - 1;
	while (temp != NULL)
	{
		y++;
	}
	close(fd);
} */

void	free_map(char **map)
{
	for (int x = 0; map[x]; x++)
		free(map[x]);
	free(map);
}

void	*map_checker(char *map_file)
{
	t_map	*map;
	char	*temp;
	int		fd;
	//char	**map;

	if (ft_strnstr(map_file, ".ber", ft_strlen(map_file)))
	{
		fd = open(map_file, O_RDONLY);
		temp = ft_calloc(1,1);
		while (temp != NULL)
		{
			temp = get_next_line(fd);
			save_map(&map, temp);
		}
		free(temp);
		close(fd);
		check_requirements(&map);
		//free_map(map.content);
		while (map != NULL)
		{
			printf("linea a enviar: %s\t len: %d\n", map->line, map->line_len);
			map = map->next;
		}
		return (map);
	}
	else
	{
		ft_putstr_fd("Error\nMap file extension is not .ber\n", STDERR_FILENO);
		exit(1);
	}
	return (NULL);
}
