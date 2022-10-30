/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:22:17 by diserran          #+#    #+#             */
/*   Updated: 2022/04/06 18:42:00 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*rsv;
	size_t	len;

	len = ft_strlen(s1) + 1;
	rsv = malloc(sizeof(char) * len);
	if (!rsv)
		return (NULL);
	ft_strlcpy(rsv, s1, len);
	return (rsv);
}
