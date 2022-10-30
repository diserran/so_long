/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:42:03 by diserran          #+#    #+#             */
/*   Updated: 2022/04/06 18:41:09 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dstf;
	const char		*srcf;

	i = 0;
	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (NULL);
	dstf = (unsigned char *)dst;
	srcf = (const char *)src;
	while (i < n)
	{
		dstf[i] = srcf[i];
		i++;
	}
	dst = dstf;
	return (dst);
}
