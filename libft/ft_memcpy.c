/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:59:30 by eruffieu          #+#    #+#             */
/*   Updated: 2014/11/07 12:14:47 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str2;

	str = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char)str2[i];
		i++;
	}
	return (dst);
}
