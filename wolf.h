/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 14:07:28 by eruffieu          #+#    #+#             */
/*   Updated: 2015/03/09 17:25:43 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "./minilibx_macos/mlx.h"
# include </opt/X11/include/X11/X.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct	s_img
{
	void	*img;
	int		bpp;
	int		end;
	int		sili;
	char	*str;
}				t_img;

typedef struct	s_env
{
	int		**tab;
	int		count;
	int		fd;
}				t_env;

typedef struct	s_text
{
	void	*img3;
	void	*img2;
	int		tbpp;
	int		tbpp2;
	int		tend;
	int		tend2;
	int		tsili;
	int		tsili2;
	char	*tstr;
	char	*tstr2;
	int		w;
	int		h;
}				t_text;

typedef struct	s_coord
{
	double	anticr;
	double	axisy;
	double	axisx;
	void	*win;
	void	*mlx;
	int		up;
	int		left;
	int		right;
	int		down;
	int		mleft;
	int		mright;
	double	angle;
	double	anglemin;
	double	dist;
	int		hauteur;
	int		x;
	int		y;
	double	x2;
	double	y2;
	int		x3;
	int		y3;
	t_img	*img;
	int		i;
	double	b;
	t_text	*st;
	int		calcb;
	int		calch;
	int		first;
	int		firstcolor;
	double	anglesave;
	double	predist;
	int		xmotion;
	int		ymotion;
	int		ssky;
	int		menu;
	t_img	*ipigeon;
	t_img	*ipen;
	t_img	*ipen2;
	int		click;
	int		ww;
	int		vabsdist;
	int		savex2;
	double	nextdist;
	double	dist2;
	int		sky;
	int		color;
	t_env	*e;
	int		touchenx;
	int		toucheny;
	int		xx;
	int		yy;
	double	*a;
	int		col;
	double	xinc;
	double	yinc;
	int		inc;
}				t_coord;

void			ft_draw(t_coord *c);
void			ft_init_win(t_coord *c);
void			drawwall(t_coord *c);
void			replace(t_coord *c, int color);
char			*replacecolor(char *str, int i, int color);
int				ft_iswall(t_coord *c);
int				ft_iswallx(int possupx, int possupy, t_coord *c);
void			to_up(t_coord *c);
void			to_down(t_coord *c);
void			to_right(t_coord *c);
void			to_left(t_coord *c);
void			inittab(t_env *c);
char			*replacetext(int i, int color, t_coord *c);
char			*text_one(char *str, t_coord *c, int i);
char			*text_two(char *str, t_coord *c, int i);
int				isempty(char *str);
char			*colorthree(char *str, int i, t_coord *c);
int				nextcolor(t_coord *c);
char			*iscorner(char *str, int i, t_coord *c, int *k);
char			*touchy(char *str, int i, t_coord *c, int *k);
char			*touchx(char *str, int i, t_coord *c, int *k);
void			increray(t_coord *c);
int				motion_notify(int x, int y, t_coord *c);
void			draw_cross(t_coord *c);
void			to_mleft(t_coord *c);
void			to_mright(t_coord *c);
void			to_xymouse(t_coord *c);
int				button_pressed(int button, int x, int y, t_coord *c);
int				button_released(int button, int x, int y, t_coord *c);
void			calcnextdist(t_coord *c);
void			check_button(t_coord *c);
void			increment_floor(t_coord *c);
void			increment_b(t_coord *c);
void			replaceforwall(t_coord *c, int color);
void			init_var(t_coord *c);
void			raypull(t_coord *c);
void			raypull2(t_coord *c, int *j);
double			*calcangle(double *a);
int				calc_advance(double angle);
void			setcolor(char *str, int pos, int col, int poos);
void			init_img(t_coord *c);

#endif
