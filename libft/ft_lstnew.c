/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:51:20 by eruffieu          #+#    #+#             */
/*   Updated: 2014/11/09 13:04:04 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*cont;

	cont = (void *)ft_memalloc(content_size + 1);
	if (!content)
	{
		cont = NULL;
		content_size = 0;
	}
	else
		cont = ft_memcpy(cont, content, content_size);
	new = (t_list *)ft_memalloc(sizeof(t_list));
	if (!new)
		return (new);
	new->content_size = content_size;
	new->next = NULL;
	new->content = cont;
	return (new);
}
