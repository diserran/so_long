/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:26:32 by diserran          #+#    #+#             */
/*   Updated: 2022/10/29 10:32:28 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"

char	**read_map(int fd, char **map)
{
	int		i = 0;
	int		line_len = 0;
	char	*line = "";
	
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		line_len = ft_strlen(line);
		map[i] = (char *) malloc(sizeof(char) * (line_len + 1));
		map[i] = line;
		map[i][line_len] = '\0';
		i++;
	}
	return (map);
}

int	main(void)
{
	int		i = 0;
	int		fd;
	char	**map;

	fd = open("map.ber", O_RDONLY);
	map = (char **) malloc(sizeof(char*) * 5);
	map = read_map(fd, map);
	fd = close(fd);
	if (map)
		printf("success");
	return (0);
}