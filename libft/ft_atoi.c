/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:29:17 by eruffieu          #+#    #+#             */
/*   Updated: 2014/11/10 09:02:44 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t			num;
	int				sign;
	int				val;

	val = 0;
	num = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	while (ft_isdigit(*str) && *str != '\0')
	{
		num = (int)(*str - '0');
		val = (val * 10) + num;
		str++;
	}
	return (val * sign);
}
