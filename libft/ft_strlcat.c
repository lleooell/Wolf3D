/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:02:03 by eruffieu          #+#    #+#             */
/*   Updated: 2014/11/10 11:00:27 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*str;
	char	*str2;
	size_t	i;

	str = ft_memchr(dst, '\0', size);
	if (str == NULL)
		return (size + ft_strlen(src));
	str2 = (char *)src;
	i = (size_t)(str - dst) + ft_strlen(str2);
	while ((size_t)(str - dst) < size - 1 && *str2 != '\0')
	{
		*str = *str2;
		str++;
		str2++;
	}
	*str = '\0';
	return (i);
}
