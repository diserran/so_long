/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:02:40 by diserran          #+#    #+#             */
/*   Updated: 2022/09/17 17:57:07 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getnumsize(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_convertnumber(int n, int numlen, char *str)
{
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[numlen] = '\0';
	while (n > 0)
	{
		str[--numlen] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		numlen;
	char	*str;

	numlen = ft_getnumsize(n);
	str = (char *)malloc(sizeof(char) * (numlen + 1));
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[numlen] = '\0';
		return (str);
	}
	if (n == -2147483648)
	{
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	else
		return (ft_convertnumber(n, numlen, str));
	return (NULL);
}
