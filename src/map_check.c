/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:26:32 by diserran          #+#    #+#             */
/*   Updated: 2022/12/07 11:40:26 by diserran         ###   ########.fr       */
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

/* static t_map	*read_map(int fd)
{
	int		i;
	//size_t	line_len;
	t_map	*temp;
	t_map	**tail;
	//char	*aux;

	i = 1;
	//line_len = 0;
	temp = (t_map*)malloc(sizeof(t_map));
	while (temp->line != NULL)
	{
		temp = (t_map *)malloc(sizeof(t_map));
		temp->line = get_next_line(fd);
		temp->next = NULL;
		if (temp->line)
		{
			temp->line_len = ft_strlen(temp->line);
			if (temp->line[temp->line_len - 1] == '\n')
				temp->line_len--;
			//temp->line = (char *) malloc(sizeof(char) * temp->line_len);
			//temp->line = ft_memcpy(temp->line, temp->line, temp->line_len);
		}
		else
			return (temp);
		*tail = temp;
		tail = &(*tail)->next;
		i++;
		printf("Mapa %d direccion %p\n", i, tail);
		printf("Mapa %d linea %s\n", i, temp->line);
		printf("Mapa %d tamaño linea %d\n", i, temp->line_len);
		printf("Mapa %d siguiente %p\n", i, temp->next);
		printf("----------------------------------------------\n");
	}
	return (0);
} */

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

/* void	*map_checker(char *map_file)
{
	t_map	*map;
	int		fd;
	//char	**map;

	if (ft_strnstr(map_file, ".ber", ft_strlen(map_file)))
	{
		fd = open(map_file, O_RDONLY);
		//map = (t_map *)malloc(sizeof(t_map));
		//map->line = get_next_line(fd);
		//map->next = NULL;
		map = read_map(fd);
		close(fd);
		//free_map(map.content);
		while (map != NULL)
		{
			printf("linea a enviar: %s", map->line);
			map = map->next;
		}
		printf("list size: %d\n", ft_lstsize((void *)map));
		return (map);
	}
	else
	{
		ft_putstr_fd("Error\nMap file extension is not .ber\n", STDERR_FILENO);
		exit(1);
	}
	return (NULL);
} */
