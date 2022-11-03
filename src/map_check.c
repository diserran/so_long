/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:26:32 by diserran          #+#    #+#             */
/*   Updated: 2022/11/02 15:49:37 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**read_map(int fd, char **map)
{
	int		i;
	int		line_len;
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
			map[i] = (char *) malloc(sizeof(char) * line_len);
			map[i] = ft_memcpy(map[i], line, line_len);
			free(line);
		}
		i++;
	}
	return (map);
}

/* int	is_rectangular(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
} */

int	main(void)
{
	int		i = 0;
	int		fd;
	char	**map;

	fd = open("map.ber", O_RDONLY);
	map = (char **) malloc(sizeof(char *) * 5);
	map = read_map(fd, map);
	fd = close(fd);
	while (i < 5)
	{
		printf("%s", map[i]);
		i++;
	}
	for (int x = 0; map[x]; x++)
		free(map[x]);
	free(map);
	return (0);
}
