/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iswall.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 10:20:08 by eruffieu          #+#    #+#             */
/*   Updated: 2015/01/14 14:40:52 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_iswall(t_coord *c)
{
	int		a;
	double	ux;
	double	uy;

	ux = c->x2;
	uy = c->y2;
	if ((int)ux < c->x)
		ux -= 0.1;
	if ((int)uy < c->y)
		uy -= 0.1;
	if (c->e->tab[(int)ux / 64][(int)uy / 64] != 0)
	{
		if (c->click == 1 && (c->anglemin - c->angle) < 0.1 &&
			(c->anglemin - c->angle) > -0.1 && c->dist < 50.0 &&
			c->e->tab[((int)ux / 64)][((int)uy / 64)] == 2)
		{
			c->e->tab[(int)ux / 64][(int)uy / 64] = 0;
			return (0);
		}
		else
			a = c->e->tab[(int)ux / 64][(int)uy / 64];
		return (a);
	}
	else
		return (0);
}

int		ft_iswallx(int possupx, int possupy, t_coord *c)
{
	if (c->e->tab[possupx / 64][possupy / 64] != 0)
		return (c->e->tab[possupx / 64][possupy / 64]);
	else
		return (0);
}

char	*text_one(char *str, t_coord *c, int i)
{
	int		t;

	if (c->touchenx == 1)
	{
		t = (((c->calcb) * 64 / c->calch) * (c->st->tsili)) +
			(((int)c->y2 - ((int)(c->y2 / 64) * 64)) * (c->st->tbpp / 8));
		str[i] = c->st->tstr[t];
		str[i + 1] = c->st->tstr[t + 1];
		str[i + 2] = c->st->tstr[t + 2];
	}
	else
	{
		t = (((c->calcb) * 64 / c->calch) * (c->st->tsili)) +
			(((int)c->x2 - ((int)(c->x2 / 64) * 64)) * (c->st->tbpp / 8));
		str[i] = c->st->tstr[t];
		str[i + 1] = c->st->tstr[t + 1];
		str[i + 2] = c->st->tstr[t + 2];
	}
	return (str);
}

char	*text_two(char *str, t_coord *c, int i)
{
	int		t;

	if (c->touchenx == 1)
	{
		t = (((c->calcb) * 64 / c->calch) * (c->st->tsili2)) +
			(((int)c->y2 - ((int)(c->y2 / 64) * 64)) * (c->st->tbpp2 / 8));
		str[i] = c->st->tstr2[t];
		str[i + 1] = c->st->tstr2[t + 1];
		str[i + 2] = c->st->tstr2[t + 2];
	}
	else
	{
		t = (((c->calcb) * 64 / c->calch) * (c->st->tsili2)) +
			(((int)c->x2 - ((int)(c->x2 / 64) * 64)) * (c->st->tbpp2 / 8));
		str[i] = c->st->tstr2[t];
		str[i + 1] = c->st->tstr2[t + 1];
		str[i + 2] = c->st->tstr2[t + 2];
	}
	return (str);
}

char	*replacetext(int i, int color, t_coord *c)
{
	if (c->menu == 1)
	{
		if (color == 1)
		{
			c->first = 1;
			c->img->str = text_one(c->img->str, c, i);
		}
		else if (color == 2)
		{
			c->first = 1;
			c->img->str = text_two(c->img->str, c, i);
		}
	}
	else
		c->img->str = colorthree(c->img->str, i, c);
	return (c->img->str);
}
