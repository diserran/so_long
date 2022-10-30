/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:33:35 by diserran          #+#    #+#             */
/*   Updated: 2022/04/10 18:46:59 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	length;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (len <= 0 || start >= length)
	{
		str = (char *)malloc(1);
		*str = '\0';
		return (str);
	}
	if (len > length)
		len = length - start;
	str = malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (s + start), (len + 1));
	return (str);
}
