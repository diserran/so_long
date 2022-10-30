/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:10:22 by diserran          #+#    #+#             */
/*   Updated: 2022/04/06 18:39:32 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dstf;
	unsigned char	*srcf;

	i = -1;
	dstf = (unsigned char *)dst;
	srcf = (unsigned char *)src;
	if (dstf || srcf)
	{
		if (dstf > srcf)
		{
			while (len--)
				dstf[len] = srcf[len];
		}
		else
		{
			while (++i < len)
				dstf[i] = srcf[i];
		}
		dst = dstf;
		return (dst);
	}
	return (NULL);
}
