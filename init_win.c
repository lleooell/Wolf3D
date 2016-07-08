/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 14:16:28 by eruffieu          #+#    #+#             */
/*   Updated: 2015/03/09 17:25:57 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			expose_hook(t_coord *c)
{
	ft_draw(c);
	return (1);
}

int			key_pressed(int keycode, t_coord *c)
{
	if (keycode == 13 || keycode == 126)
		c->up = 1;
	else if (keycode == 1 || keycode == 125)
		c->down = 1;
	else if (keycode == 123)
		c->left = 1;
	else if (keycode == 124)
		c->right = 1;
	else if (keycode == 0)
		c->mleft = 1;
	else if (keycode == 2)
		c->mright = 1;
	else if (keycode == 96)
		c->menu *= -1;
	else if (keycode == 18)
	{
		if (c->anticr >= 0.05)
			c->anticr -= 0.05;
	}
	else if (keycode == 19)
		if (c->anticr <= 0.95)
			c->anticr += 0.05;
	return (1);
}

int			key_released(int keycode, t_coord *c)
{
	if (keycode == 13 || keycode == 126)
		c->up = 0;
	else if (keycode == 1 || keycode == 125)
		c->down = 0;
	else if (keycode == 123)
		c->left = 0;
	else if (keycode == 124)
		c->right = 0;
	else if (keycode == 0)
		c->mleft = 0;
	else if (keycode == 2)
		c->mright = 0;
	else if (keycode == 25)
	{
		c->axisx -= 0.9;
		c->axisy -= 0.5;
	}
	else if (keycode == 29)
	{
		c->axisx += 0.5;
		c->axisy += 0.5;
	}
	else if (keycode == 53)
		exit(0);
	return (0);
}

int			loop_hook(t_coord *c)
{
	c->inc++;
	if (c->inc % 2 == 0)
		expose_hook(c);
	return (0);
}

void		ft_init_win(t_coord *c)
{
	init_img(c);
	mlx_expose_hook(c->win, expose_hook, c);
	mlx_hook(c->win, KeyPress, KeyPressMask, key_pressed, c);
	mlx_hook(c->win, KeyRelease, KeyReleaseMask, key_released, c);
	mlx_hook(c->win, MotionNotify, PointerMotionMask, motion_notify, c);
	mlx_hook(c->win, ButtonPress, ButtonPressMask, button_pressed, c);
	mlx_hook(c->win, ButtonRelease, ButtonReleaseMask, button_released, c);
	mlx_loop_hook(c->mlx, loop_hook, c);
	mlx_loop(c->mlx);
}
