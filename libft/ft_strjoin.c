/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:59:14 by eruffieu          #+#    #+#             */
/*   Updated: 2014/11/07 13:10:49 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strl(char const *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*str;

	if (s1 && s2)
	{
		i = 0;
		len = (ft_strl(s1) + ft_strl(s2));
		str = (char *)malloc((len + 1) * sizeof(*str));
		if (str == NULL)
			return (NULL);
		len = 0;
		while (s1[i])
			str[len++] = s1[i++];
		i = 0;
		while (s2[i])
			str[len++] = s2[i++];
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
