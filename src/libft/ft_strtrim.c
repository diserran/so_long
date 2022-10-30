/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:23:17 by diserran          #+#    #+#             */
/*   Updated: 2022/10/30 22:29:07 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	getstart(char const *str, char const *set)
{
	size_t	i;
	int		start_pos;

	i = 0;
	start_pos = 0;
	while (str[i] && start_pos == 0)
	{
		if (ft_strchr(set, str[i]) == 0)
			return (i);
		i++;
	}
	return (i);
}

static size_t	getend(char const *str, char const *set)
{
	size_t	i;
	size_t	length;

	i = 0;
	length = ft_strlen(str);
	while (i < length)
	{
		if (ft_strchr(set, str[(length - i) - 1]) == 0)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	length;
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	length = ft_strlen(s1);
	start = getstart(s1, set);
	end = length - getend(s1, set);
	if (start < end)
		return (ft_substr(s1, start, end - start));
	str = malloc(1);
	*str = '\0';
	return (str);
}
