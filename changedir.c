/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changedir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 10:17:58 by eruffieu          #+#    #+#             */
/*   Updated: 2015/01/22 14:41:33 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	to_up(t_coord *c)
{
	double		possupx;
	double		possupy;

	possupy = c->y - (sin((((c->angle) / 180.0) * M_PI)) * 10.0);
	possupx = c->x + (cos((((c->angle) / 180.0) * M_PI)) * 10.0);
	if (ft_iswallx((int)possupx, (int)possupy, c) == 0)
	{
		possupy = c->y - (sin((((c->angle - 30.0) / 180.0) * M_PI)) * 10.0);
		possupx = c->x + (cos((((c->angle - 30.0) / 180.0) * M_PI)) * 10.0);
		if (ft_iswallx((int)possupx, (int)possupy, c) == 0)
		{
			possupy = c->y - (sin((((c->angle + 30.0) / 180.0) * M_PI)) * 10.0);
			possupx = c->x + (cos((((c->angle + 30.0) / 180.0) * M_PI)) * 10.0);
			if (ft_iswallx((int)possupx, (int)possupy, c) == 0)
			{
				c->y -= (sin((((c->angle) / 180.0) * M_PI)) * 10.0);
				c->x += (cos((((c->angle) / 180.0) * M_PI)) * 10.0);
			}
		}
	}
}

void	to_down(t_coord *c)
{
	double		possupx;
	double		possupy;

	possupy = c->y + (sin((((c->angle) / 180.0) * M_PI)) * 10.0);
	possupx = c->x - (cos((((c->angle) / 180.0) * M_PI)) * 10.0);
	if (ft_iswallx((int)possupx, (int)possupy, c) == 0)
	{
		possupy = c->y + (sin((((c->angle - 30.0) / 180.0) * M_PI)) * 10.0);
		possupx = c->x - (cos((((c->angle - 30.0) / 180.0) * M_PI)) * 10.0);
		if (ft_iswallx((int)possupx, (int)possupy, c) == 0)
		{
			possupy = c->y + (sin((((c->angle + 30.0) / 180.0) * M_PI)) * 10.0);
			possupx = c->x - (cos((((c->angle + 30.0) / 180.0) * M_PI)) * 10.0);
			if (ft_iswallx((int)possupx, (int)possupy, c) == 0)
			{
				c->y += (sin((((c->angle) / 180.0) * M_PI)) * 10.0);
				c->x -= (cos((((c->angle) / 180.0) * M_PI)) * 10.0);
			}
		}
	}
}

void	to_left(t_coord *c)
{
	c->angle = c->angle - (60.0 / 1024.0) * 50.0;
	if (c->angle < 0.0)
		c->angle = 360.0 + c->angle;
}

void	to_right(t_coord *c)
{
	c->angle = c->angle + (60.0 / 1024.0) * 50.0;
	if (c->angle >= 360.0)
		c->angle = 0.0 + (c->angle - 360.0);
}

char	*colorthree(char *str, int i, t_coord *c)
{
	static int k = 1;

	c->col = ((int)c->dist / 4);
	if (255 - c->col < 0)
		c->col = 255;
	if ((c->x2 < (double)(c->xx) + 0.1 && c->x2 > (double)(c->xx) - 0.1) &&
		(c->y2 < (double)(c->yy) + 0.1 && c->y2 > (double)(c->yy) - 0.1))
		str = iscorner(str, i, c, &k);
	else
	{
		if (c->touchenx == 1)
			str = touchx(str, i, c, &k);
		else if (c->toucheny == 1)
			str = touchy(str, i, c, &k);
		c->first = 0;
	}
	return (str);
}
