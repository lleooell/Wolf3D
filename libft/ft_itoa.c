/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:22:48 by eruffieu          #+#    #+#             */
/*   Updated: 2014/11/10 09:08:27 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_length(int i, size_t *len, int *size)
{
	*len = 1;
	if (i >= 0)
	{
		*len = 0;
		i = -i;
	}
	*size = 1;
	while (i / *size < -9)
	{
		*size *= 10;
		*len += 1;
	}
}

char			*ft_itoa(int n)
{
	size_t	len;
	int		size;
	size_t	pos;
	char	*str;

	ft_length(n, &len, &size);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	pos = 0;
	if (n < 0)
	{
		str[pos] = '-';
		pos++;
	}
	if (n > 0)
		n = -n;
	while (size >= 1)
	{
		str[pos++] = -(n / size % 10) + 48;
		size /= 10;
	}
	str[pos] = '\0';
	return (str);
}
