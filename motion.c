/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 10:56:19 by eruffieu          #+#    #+#             */
/*   Updated: 2015/03/09 18:10:29 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		motion_notify(int x, int y, t_coord *c)
{
	c->xmotion = x;
	c->ymotion = y;
	to_xymouse(c);
	return (0);
}

void	draw_cross(t_coord *c)
{
	mlx_pixel_put(c->mlx, c->win, 512, 390, 0xFFFFFF);
	mlx_pixel_put(c->mlx, c->win, 512, 389, 0xFFFFFF);
	mlx_pixel_put(c->mlx, c->win, 512, 388, 0xFFFFFF);
	mlx_pixel_put(c->mlx, c->win, 512, 387, 0xFFFFFF);
	mlx_pixel_put(c->mlx, c->win, 512, 391, 0xFFFFFF);
	mlx_pixel_put(c->mlx, c->win, 512, 392, 0xFFFFFF);
	mlx_pixel_put(c->mlx, c->win, 512, 393, 0xFFFFFF);
	mlx_pixel_put(c->mlx, c->win, 511, 390, 0xFFFFFF);
	mlx_pixel_put(c->mlx, c->win, 510, 390, 0xFFFFFF);
	mlx_pixel_put(c->mlx, c->win, 509, 390, 0xFFFFFF);
	mlx_pixel_put(c->mlx, c->win, 513, 390, 0xFFFFFF);
	mlx_pixel_put(c->mlx, c->win, 514, 390, 0xFFFFFF);
	mlx_pixel_put(c->mlx, c->win, 515, 390, 0xFFFFFF);
}

void	to_mleft(t_coord *c)
{
	double		possupx;
	double		possupy;

	possupy = c->y - (sin((((c->angle - 90.0) / 180.0) * M_PI)) * 10.0);
	possupx = c->x + (cos((((c->angle - 90.0) / 180.0) * M_PI)) * 10.0);
	if (ft_iswallx((int)possupx, (int)possupy, c) == 0)
	{
		possupy = c->y - (sin((((c->angle - 30.0 - 90.0) /
								180.0) * M_PI)) * 10.0);
		possupx = c->x + (cos((((c->angle - 30.0 - 90.0) /
								180.0) * M_PI)) * 10.0);
		if (ft_iswallx((int)possupx, (int)possupy, c) == 0)
		{
			possupy = c->y - (sin((((c->angle + 30.0 - 90.0) /
									180.0) * M_PI)) * 10.0);
			possupx = c->x + (cos((((c->angle + 30.0 - 90.0) /
									180.0) * M_PI)) * 10.0);
			if (ft_iswallx((int)possupx, (int)possupy, c) == 0)
			{
				c->y -= (sin((((c->angle - 90.0) / 180.0) * M_PI)) * 10.0);
				c->x += (cos((((c->angle - 90.0) / 180.0) * M_PI)) * 10.0);
			}
		}
	}
}

void	to_mright(t_coord *c)
{
	double		possupx;
	double		possupy;

	possupy = c->y - (sin((((c->angle + 90.0) / 180.0) * M_PI)) * 10.0);
	possupx = c->x + (cos((((c->angle + 90.0) / 180.0) * M_PI)) * 10.0);
	if (ft_iswallx((int)possupx, (int)possupy, c) == 0)
	{
		possupy = c->y - (sin((((c->angle - 90.0 + 90.0) /
								180.0) * M_PI)) * 10.0);
		possupx = c->x + (cos((((c->angle - 90.0 + 90.0) /
								180.0) * M_PI)) * 10.0);
		if (ft_iswallx((int)possupx, (int)possupy, c) == 0)
		{
			possupy = c->y - (sin((((c->angle + 90.0 + 90.0) /
									180.0) * M_PI)) * 10.0);
			possupx = c->x + (cos((((c->angle + 90.0 + 90.0) /
									180.0) * M_PI)) * 10.0);
			if (ft_iswallx((int)possupx, (int)possupy, c) == 0)
			{
				c->y -= (sin((((c->angle + 90.0) / 180.0) * M_PI)) * 10.0);
				c->x += (cos((((c->angle + 90.0) / 180.0) * M_PI)) * 10.0);
			}
		}
	}
}

void	to_xymouse(t_coord *c)
{
	if (c->xmotion < 1024 && c->xmotion > 0
		&& c->ymotion > 0 && c->ymotion < 780)
	{
		c->angle = (double)(((60.0 / 1024.0) * 19.0) * (double)c->xmotion);
		c->ymotion = 780 - c->ymotion;
		if (c->angle > 360.0)
			c->angle = 0.0 + (c->angle - 360.0);
		if (c->angle > 360.0)
			c->angle = 0.0 + (c->angle - 360.0);
		if (c->angle > 360.0)
			c->angle = 0.0 + (c->angle - 360.0);
		c->ssky = (c->ymotion - 390) * c->axisy;
	}
}
