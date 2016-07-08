/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 11:19:17 by eruffieu          #+#    #+#             */
/*   Updated: 2015/03/09 16:55:07 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	increment_b(t_coord *c)
{
	while ((c->b + c->ssky) < -2)
	{
		(c->b)++;
		(c->calcb)++;
	}
}

void	increment_floor(t_coord *c)
{
	while ((c->hauteur + c->ssky) <= -2)
		(c->hauteur)++;
}

void	replaceforwall(t_coord *c, int color)
{
	while ((c->b + c->ssky) <= (c->hauteur + c->ssky) &&
		(c->b + c->ssky) <= 779 && (c->b + c->ssky) >= -2)
	{
		c->img->str = replacetext(((((c->b + c->ssky)) * (c->img->sili)) +
								c->i * (c->img->bpp / 8)), color, c);
		(c->b)++;
		(c->calcb)++;
	}
}

void	init_var(t_coord *c)
{
	c->up = 0;
	c->down = 0;
	c->left = 0;
	c->right = 0;
	c->axisx = 2.0;
	c->axisy = 3;
	c->anticr = 0.7;
	c->x = 96;
	c->y = 96;
	c->x2 = 0;
	c->y2 = 0;
	c->dist = 0;
	c->angle = 0.0;
	c->ymotion = 0;
	c->xmotion = 0;
	c->ssky = 0;
	c->menu = -1;
	c->mleft = 0;
	c->mright = 0;
	c->click = 0;
	c->inc = 0;
}

void	setcolor(char *str, int pos, int col, int poos)
{
	int		y;

	y = 0;
	while (y <= 2)
	{
		if (y == poos)
			str[pos + y] = col;
		else
			str[pos + y] = 0;
		y++;
	}
}
