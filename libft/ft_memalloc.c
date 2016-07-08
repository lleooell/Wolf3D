/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:34:39 by eruffieu          #+#    #+#             */
/*   Updated: 2014/11/11 16:02:55 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void		*memspace;

	memspace = (void *)malloc(size * sizeof(void));
	if (!memspace)
		return (NULL);
	return (ft_memset(memspace, 0, size));
}
