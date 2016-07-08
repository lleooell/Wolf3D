/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:12:00 by eruffieu          #+#    #+#             */
/*   Updated: 2014/11/07 12:31:23 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str2;
	unsigned char	*temp;

	i = 0;
	str = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	temp = (unsigned char *)malloc(len * sizeof(*temp));
	while (i < len)
	{
		temp[i] = str2[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		str[i] = temp[i];
		i++;
	}
	free(temp);
	return (dst);
}
