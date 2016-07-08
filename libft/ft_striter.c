/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 09:44:28 by eruffieu          #+#    #+#             */
/*   Updated: 2014/11/06 10:05:13 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int		i;
	int		len;

	if (s && f)
	{
		len = 0;
		i = 0;
		while (s[len])
			len++;
		while (i < len)
		{
			f(s);
			s++;
			i++;
		}
	}
}
