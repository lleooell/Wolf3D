/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:15:07 by eruffieu          #+#    #+#             */
/*   Updated: 2014/11/07 13:11:13 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_checkstartspace(char const *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		return (-1);
	return (i);
}

static int		ft_checkendspace(char const *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	len--;
	while (str[len] == ' ' || str[len] == '\n' || str[len] == '\t')
		len--;
	return (len);
}

static char		*ft_vide(void)
{
	char	*str;

	str = (char *)malloc(1 * sizeof(*str));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		len;
	int		start;
	int		end;

	if (s == NULL)
		return (NULL);
	len = 0;
	start = ft_checkstartspace(s);
	if (start == -1)
		return (ft_vide());
	end = ft_checkendspace(s);
	while (s[len])
		len++;
	str = (char *)malloc((len - start - (len - end) + 2) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	len = 0;
	while (start <= end)
		str[len++] = s[start++];
	str[len] = '\0';
	return (str);
}
