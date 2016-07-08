/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 14:31:02 by eruffieu          #+#    #+#             */
/*   Updated: 2015/03/09 16:57:44 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_draw(t_coord *c)
{
	check_button(c);
	c->i = 0;
	c->anglemin = c->angle - (60.0 / 1024.0) * 512.0;
	if (c->anglemin < 0.0)
		c->anglemin = 360.0 + c->anglemin;
	c->first = 1;
	c->predist = 1.0;
	drawwall(c);
	mlx_put_image_to_window(c->mlx, c->win, c->img->img, 0, 0);
	draw_cross(c);
	if (c->click == 0)
		mlx_put_image_to_window(c->mlx, c->win, c->ipen2->img, 437, 600);
	else
		mlx_put_image_to_window(c->mlx, c->win, c->ipen->img, 567, 600);
}

void		drawwall(t_coord *c)
{
	while (c->i < 1024)
	{
		c->b = -2;
		c->dist = 0.05;
		if ((c->anglemin += (60.00 / 1024.00)) >= 360.00)
			c->anglemin = 0.0 + (60.00 / 1024.00);
		c->x2 = (double)c->x;
		c->y2 = (double)c->y;
		c->color = 0;
		raypull(c);
		c->dist = c->dist * cos((fabs(c->angle - c->anglemin) / 180.0) * M_PI);
		c->hauteur = (64.0 / c->dist) * 675.0;
		c->b = (780 - c->hauteur) / 2;
		replace(c, c->color);
		c->predist = c->dist;
		(c->i)++;
	}
}

void		replace(t_coord *c, int color)
{
	c->hauteur += c->b;
	c->calcb = -2;
	c->calch = (c->hauteur - c->b);
	c->sky = -2;
	c->ww = 1;
	while (c->sky < (c->b + c->ssky) && c->sky <= 779 && c->sky >= -2)
	{
		c->img->str = replacecolor(c->img->str, (((c->sky * (c->img->sili))) +
								c->i * (c->img->bpp / 8)), 8);
		(c->sky)++;
	}
	increment_b(c);
	replaceforwall(c, color);
	increment_floor(c);
	while ((c->hauteur + c->ssky) <= 779 && (c->hauteur + c->ssky) >= -2)
	{
		c->img->str = replacecolor(c->img->str, ((((c->hauteur + c->ssky)) *
						(c->img->sili)) + c->i * (c->img->bpp / 8)), 7);
		(c->hauteur)++;
	}
}

char		*replacecolor(char *str, int i, int color)
{
	if (color == 7)
	{
		str[i] = 200;
		str[i + 1] = 200;
		str[i + 2] = 200;
	}
	else if (color == 8)
	{
		str[i] = 255;
		str[i + 1] = 255;
		str[i + 2] = 0;
	}
	return (str);
}

int			main(void)
{
	t_coord	c;

	if (!(c.img = (t_img *)malloc(sizeof(t_img))) ||
		!(c.st = (t_text *)malloc(sizeof(t_text))) ||
		!(c.ipen = (t_img *)malloc(sizeof(t_img))) ||
		!(c.ipen2 = (t_img *)malloc(sizeof(t_img))) ||
		!(c.e = (t_env *)malloc(sizeof(t_env))))
		return (-1);
	inittab(c.e);
	c.a = calcangle(c.a);
	init_var(&c);
	ft_init_win(&c);
	mlx_destroy_image(c.mlx, c.img->img);
	return (0);
}
