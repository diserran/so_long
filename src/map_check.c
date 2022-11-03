/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:26:32 by diserran          #+#    #+#             */
/*   Updated: 2022/11/03 15:43:12 by diserran         ###   ########.fr       */
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

int	is_rectangular(char **map)
{
	int		i;
	size_t	initial_len;

	i = 0;
	initial_len = ft_strlen(map[0]);
	while (map[i])
	{
		printf("Initial len: %zu\t Line %d len: %zu\n", initial_len, i, ft_strlen(map[i]));
		if (initial_len != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

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
	if (is_rectangular(map))
		printf("\nThe map is rectangular");
	else
		printf("\nThe map is NOT rectanguar!!!");
	for (int x = 0; map[x]; x++)
		free(map[x]);
	free(map);
	return (0);
}
