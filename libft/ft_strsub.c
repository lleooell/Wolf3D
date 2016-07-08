/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:53:23 by eruffieu          #+#    #+#             */
/*   Updated: 2014/11/11 16:30:02 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		count;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	count = start + len;
	str = (char *)malloc((len + 1) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	while (start < count && s[start])
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
