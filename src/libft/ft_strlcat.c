/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:30:37 by diserran          #+#    #+#             */
/*   Updated: 2022/03/25 16:49:50 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	j = dst_len;
	if (size == 0)
		return (src_len);
	else if (size < dst_len)
		return (src_len + size);
	else
	{
		while (src[i] && (dst_len + i) < size)
			dst[j++] = src[i++];
		if ((dst_len + i) == size && dst_len < size)
			dst[--j] = '\0';
		else
			dst[j] = '\0';
		return (src_len + dst_len);
	}
}
