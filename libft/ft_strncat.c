/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:56:46 by eruffieu          #+#    #+#             */
/*   Updated: 2014/11/10 09:33:40 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *str;

	str = s1;
	while (*str != '\0')
		str++;
	while (*s2 && n > 0)
	{
		*str = *s2;
		str++;
		s2++;
		n--;
	}
	*str = '\0';
	return (s1);
}
