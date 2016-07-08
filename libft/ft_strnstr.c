/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:18:10 by eruffieu          #+#    #+#             */
/*   Updated: 2014/11/06 20:21:23 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	a;
	char	b;
	size_t	len;
	int		i;

	i = 0;
	if ((a = *s2++) != '\0')
	{
		len = ft_strlen(s2);
		while (!i || ft_strncmp(s1, s2, len) != 0)
		{
			i = 1;
			if ((b = *s1++) == '\0' || n-- < 1)
				return (NULL);
			while (b != a)
			{
				if ((b = *s1++) == '\0' || n-- < 1)
					return (NULL);
			}
			if (len > n)
				return (NULL);
		}
		s1--;
	}
	return ((char *)s1);
}
