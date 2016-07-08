/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:10:15 by eruffieu          #+#    #+#             */
/*   Updated: 2014/11/07 12:38:41 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*str;

	if (s && f)
	{
		i = 0;
		len = 0;
		while (s[len])
			len++;
		str = (char *)malloc(len * sizeof(*str));
		if (str == NULL)
			return (0);
		while (i < len)
		{
			str[i] = f(s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
