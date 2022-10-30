/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:46:45 by diserran          #+#    #+#             */
/*   Updated: 2022/04/15 17:10:20 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_splitcount(const char *s, char c)
{
	int		words;
	int		i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

static char	**ft_splitlogic(const char *s, char c)
{
	int		i;
	int		j;
	int		start;
	int		length;
	char	**str;

	i = -1;
	j = 0;
	start = -1;
	length = ft_strlen(s);
	str = (char **) malloc(sizeof(char *) * (ft_splitcount(s, c) + 1));
	if (!str || sizeof(str) == 0)
		return (NULL);
	while (++i <= length)
	{
		if (s[i] != c && start < 0)
			start = i;
		else if (start >= 0 && (s[i] == c || i == length))
		{
			str[j++] = ft_substr(s, start, (i - start));
			start = -1;
		}
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	if (!s)
		return (NULL);
	return (ft_splitlogic(s, c));
}
