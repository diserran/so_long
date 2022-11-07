/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:26:32 by diserran          #+#    #+#             */
/*   Updated: 2022/11/07 13:22:00 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

void	map_checker(char *mapfile)
{
	int		fd;
	int		i;
	char	**map;

	i = 0;
	if (ft_strnstr(mapfile, ".ber", ft_strlen(mapfile)))
	{
		fd = open(mapfile, O_RDONLY);
		map = (char **) malloc(sizeof(char *) * 5);
		map = read_map(fd, map);
		fd = close(fd);
		while (i < 5)
		{
			printf("%s\n", map[i]);
			i++;
		}
		if (is_rectangular(map))
			printf("\nThe map is rectangular");
		else
			printf("\nThe map is NOT rectanguar!!!");
		for (int x = 0; map[x]; x++)
			free(map[x]);
		free(map);
	}
	else
	{
		write(2, "Error\n", 7);
		write(2, "Map file extension is not .ber\n", 32);
		exit(1);
	}
}
