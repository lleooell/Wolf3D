/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:04:24 by eruffieu          #+#    #+#             */
/*   Updated: 2014/11/11 16:03:52 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*str;
	const char	*str2;

	str = dst;
	str2 = src;
	while (n--)
	{
		if (*str2 == c)
		{
			*str++ = *str2++;
			return (str);
		}
		*str++ = *str2++;
	}
	return (NULL);
}
