/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 11:18:37 by eruffieu          #+#    #+#             */
/*   Updated: 2015/03/09 17:25:34 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	raypull(t_coord *c)
{
	int		y;

	y = calc_advance(c->anglemin);
	while (c->anglemin != c->a[y])
		y++;
	while (c->color == 0)
	{
		c->x2 = (double)c->x + c->a[y + 1] * c->dist;
		c->y2 = (double)c->y - c->a[y + 2] * c->dist;
		c->dist += 0.10;
		c->xx = (int)((int)c->x2 / 64) * 64;
		c->yy = (int)((int)c->y2 / 64) * 64;
		if (c->x2 < (double)(c->xx) + 0.1 && c->x2 > (double)(c->xx) - 0.2)
		{
			c->touchenx = 1;
			c->toucheny = 0;
			c->color = ft_iswall(c);
		}
		if (c->y2 < (double)(c->yy) + 0.1 && c->y2 > (double)(c->yy) - 0.2)
		{
			c->toucheny = 1;
			c->touchenx = 0;
			c->color = ft_iswall(c);
		}
	}
}

void	raypull2(t_coord *c, int *j)
{
	int		y;

	y = calc_advance(c->anglesave);
	while (c->anglesave != c->a[y])
		y++;
	while (*j == 0)
	{
		c->x2 = (double)c->x + c->a[y + 1] * c->dist2;
		c->y2 = (double)c->y - c->a[y + 2] * c->dist2;
		c->xx = (int)((c->x2) / 64) * 64;
		c->yy = (int)((c->y2) / 64) * 64;
		c->dist2 += 0.10;
		if (c->x2 < (double)(c->xx) + 0.1 && c->x2 > (double)(c->xx) - 0.2)
		{
			c->touchenx = 1;
			c->toucheny = 0;
			*j = ft_iswall(c);
		}
		if (c->y2 < (double)(c->yy) + 0.1 && c->y2 > (double)(c->yy) - 0.2)
		{
			c->toucheny = 1;
			c->touchenx = 0;
			*j = ft_iswall(c);
		}
	}
}

double	*calcangle(double *a)
{
	int		h;
	double	angler;

	h = 0;
	angler = 0.0;
	while (angler <= 360.0)
	{
		angler += (60.0 / 1024.0);
		h++;
	}
	if (!(a = (double *)malloc((3 * h) * sizeof(double))))
		return (0);
	angler = 0.0;
	h = 0;
	while (angler < 360.0)
	{
		a[h] = angler;
		a[h + 1] = cos((angler / 180.0) * M_PI);
		a[h + 2] = sin((angler / 180.0) * M_PI);
		angler += (60.0 / 1024.0);
		h += 3;
	}
	return (a);
}

int		calc_advance(double angle)
{
	if (angle >= 0.0 && angle <= 90.0)
		return (0);
	else if (angle >= 45.0 && angle <= 90.0)
		return (2250);
	else if (angle >= 90.0 && angle <= 180.0)
		return (4500);
	else if (angle >= 180.0 && angle <= 225.0)
		return (6750);
	else if (angle >= 225.0 && angle <= 270.0)
		return (9000);
	else if (angle >= 270.0 && angle <= 315.0)
		return (11250);
	else
		return (13500);
}

void	init_img(t_coord *c)
{
	if (!(c->mlx = mlx_init()) ||
		!(c->win = mlx_new_window(c->mlx, 1024, 780, "Wolf3D")) ||
	!(c->st->img2 = mlx_xpm_file_to_image(c->mlx, "wall.xpm",
				&(c->st->w), &(c->st->h))) ||
	!(c->st->tstr = mlx_get_data_addr(c->st->img2,
				&(c->st->tbpp), &(c->st->tsili), &(c->st->tend))) ||
	!(c->st->img3 = mlx_xpm_file_to_image(c->mlx, "wood.xpm",
				&(c->st->w), &(c->st->h))) ||
	!(c->st->tstr2 = mlx_get_data_addr(c->st->img3,
				&(c->st->tbpp2), &(c->st->tsili2), &(c->st->tend2))) ||
	!(c->ipen->img = mlx_xpm_file_to_image(c->mlx, "pen.xpm",
										&(c->st->w), &(c->st->h))) ||
	!(c->ipen2->img = mlx_xpm_file_to_image(c->mlx, "pen2.xpm",
										&(c->st->w), &(c->st->h))) ||
	!(c->img->img = mlx_new_image(c->mlx, 1024, 780)) ||
	!(c->img->str = mlx_get_data_addr(c->img->img,
							&(c->img->bpp), &(c->img->sili), &(c->img->end))))
		exit(0);
}
