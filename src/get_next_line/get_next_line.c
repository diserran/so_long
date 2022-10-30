/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:35:29 by diserran          #+#    #+#             */
/*   Updated: 2022/10/30 22:37:19 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_join(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

static char	*ft_read_fd(int fd, char *str)
{
	char		*buffer;
	ssize_t		reader;

	if (!str)
		str = ft_calloc(1, 1);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	reader = 1;
	while (reader > 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[reader] = '\0';
		str = ft_join(str, buffer);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

static char	*ft_trim_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char	*ft_next_line(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(str) - i) + 1, sizeof(char));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		line[j++] = str[i++];
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*static_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	static_line = ft_read_fd(fd, static_line);
	if (!static_line)
		return (NULL);
	line = ft_trim_line(static_line);
	static_line = ft_next_line(static_line);
	return (line);
}
