/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corner_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 10:56:40 by eruffieu          #+#    #+#             */
/*   Updated: 2015/01/07 11:25:22 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		button_pressed(int button, int x, int y, t_coord *c)
{
	c->click = x - button + y;
	c->click = 1;
	return (0);
}

int		button_released(int button, int x, int y, t_coord *c)
{
	c->click = x - button + y;
	c->click = 0;
	return (0);
}

void	check_button(t_coord *c)
{
	if (c->up == 1)
		to_up(c);
	if (c->down == 1)
		to_down(c);
	if (c->left == 1)
		to_left(c);
	if (c->right == 1)
		to_right(c);
	if (c->mleft == 1)
		to_mleft(c);
	if (c->mright == 1)
		to_mright(c);
}
