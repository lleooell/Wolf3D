/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:02:42 by eruffieu          #+#    #+#             */
/*   Updated: 2014/11/06 10:05:46 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int		len;
	unsigned int		i;

	i = 0;
	len = 0;
	if (s && f)
	{
		while (s[len])
			len++;
		while (i < len)
		{
			f(i, s);
			s++;
			i++;
		}
	}
}
