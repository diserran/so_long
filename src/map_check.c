/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:26:32 by diserran          #+#    #+#             */
/*   Updated: 2022/11/12 17:06:01 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

struct mapData {
	char	**content;
	int		**size;
};

static char	**read_map(int fd, char **map)
{
	int		i;
	size_t	line_len;
	char	*line;

	i = 0;
	line_len = 0;
	line = "";
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
	return (map);
}

static int	is_rectangular(char **map)
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
}

int	get_dimensions(char *map_file, int	**size)
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
}

void	free_map(char **map)
{
	for (int x = 0; map[x]; x++)
		free(map[x]);
	free(map);
}

void	map_checker(char *map_file)
{
	struct	mapData map;
	int		fd;
	//char	**map;

	if (ft_strnstr(map_file, ".ber", ft_strlen(map_file)))
	{
		fd = open(map_file, O_RDONLY);
		map.content = (char **) malloc(sizeof(char *) * 5);
		map.content = read_map(fd, map.content);
		close(fd);
		for (int i = 0; i < 5; i++)
			printf("%s\n", map.content[i]);
		if (is_rectangular(map.content))
			printf("\nThe map is rectangular\n");
		else
			printf("\nThe map is NOT rectanguar!!!\n");
		free_map(map.content);
	}
	else
	{
		write(2, "Error\n", 7);
		write(2, "Map file extension is not .ber\n", 32);
		exit(1);
	}
}
