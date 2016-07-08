/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 15:42:32 by eruffieu          #+#    #+#             */
/*   Updated: 2015/03/09 16:39:27 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char	*iscorner(char *str, int i, t_coord *c, int *k)
{
	c->vabsdist = (int)(c->predist - c->dist);
	if (c->vabsdist > 1)
		c->first = 1;
	if (c->first == 1)
		*k = nextcolor(c);
	if (*k == 1)
		setcolor(str, i, (255 - c->col), 0);
	else if (*k == 2)
	{
		str[i] = (255 - c->col);
		str[i + 2] = (255 - c->col);
		str[i + 1] = 0;
	}
	else if (*k == 3)
		setcolor(str, i, (255 - c->col), 1);
	else if (*k == 4)
		setcolor(str, i, (255 - c->col), 2);
	return (str);
}

char	*touchx(char *str, int i, t_coord *c, int *k)
{
	if ((int)c->x2 < c->x)
	{
		*k = 1;
		str[i] = (255 - c->col);
		str[i + 1] = 0;
		str[i + 2] = 0;
	}
	else
	{
		str[i] = (255 - c->col);
		str[i + 1] = 0;
		str[i + 2] = (255 - c->col);
		*k = 2;
	}
	return (str);
}

char	*touchy(char *str, int i, t_coord *c, int *k)
{
	if ((int)c->y2 < c->y)
	{
		str[i + 1] = (255 - c->col);
		str[i] = 0;
		str[i + 2] = 0;
		*k = 3;
	}
	else
	{
		str[i + 2] = (255 - c->col);
		str[i] = 0;
		str[i + 1] = 0;
		*k = 4;
	}
	return (str);
}

int		nextcolor(t_coord *c)
{
	increray(c);
	if (c->touchenx == 1)
	{
		if (c->x2 <= c->x)
			return (1);
		else
			return (2);
	}
	else
	{
		if (c->y2 <= c->y)
			return (3);
		else
			return (4);
	}
	return (1);
}

void	increray(t_coord *c)
{
	int		j;

	c->anglesave = c->anglemin;
	while ((c->x2 < (double)(c->xx) + 0.1 && c->x2 > (double)(c->xx) - 0.1) &&
		(c->y2 < (double)(c->yy) + 0.1 && c->y2 > (double)(c->yy) - 0.1))
	{
		c->anglesave += (60.00 / 1024.00) * 10.0;
		if (c->anglesave >= 360.00)
			c->anglesave = 0.0 + (60.00 / 1024.00);
		c->dist2 = 1.0;
		c->x2 = (double)c->x;
		c->y2 = (double)c->y;
		j = 0;
		raypull2(c, &j);
	}
}
