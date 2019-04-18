/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:13:45 by bbataini          #+#    #+#             */
/*   Updated: 2018/09/14 15:26:49 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		init_mandelbrot(t_win *w)
{
	w->fractal = MANDELBROT;
	w->xmin = -2.1;
	w->xmax = 0.6;
	w->ymin = -1.2;
	w->ymax = 1.2;
	w->xoffset = 0;
	w->yoffset = 0;
	w->v = 1;
	w->c = 1;
	w->a = 0;
	w->zr = 0;
	w->zi = 0;
	w->ji = 0;
	w->iteration_max = 60;
	w->iteration_maxi = 150;
	ft_putstr("\n**** Fractal de Mandelbrot ****\n\n\n");
	ft_putstr("Couleur : '9' '0' '-' '=' 'a' 's' \n");
	ft_putstr("Deplacement : Fleche\nIterations : 'o' / 'p' \n ");
	ft_putstr("Zoom : souris \n");
	return (0);
}

void	pxl_to_img(t_win *w, char r, char g, char b)
{
	int x;
	int y;

	x = w->x + w->xoffset;
	y = w->y + w->yoffset;
	if (x < w->winsx && y < w->winsy && x > 0 && y > 0)
	{
		x = x * w->bpp;
		y = y * w->img->sizeline;
		w->img->data[x + y] = r;
		w->img->data[x + 1 + y] = g;
		w->img->data[x + 2 + y] = b;
	}
}

void	trace(t_win *w)
{
	w->i = 0;
	while ((w->zr * w->zr) + (w->zi * w->zi) < 4 && w->i < w->iteration_max)
	{
		w->tmp = w->zr;
		w->zr = (w->zr * w->zr) - (w->zi * w->zi) + w->cr;
		w->zi = 2 * w->zi * w->tmp + w->ci + w->ji;
		w->i++;
	}
	if (w->i != w->iteration_max)
	{
		pxl_to_img(w, w->color[w->c].r * w->i * w->v / w->iteration_max,\
				w->color[w->c].g * w->i * w->v / w->iteration_max  \
				, w->color[w->c].b * w->i * w->v / w->iteration_max);
	}
	else if (w->a >= 1)
	{
		pxl_to_img(w, w->color[w->a].r * w->i * w->v / w->iteration_max,\
				w->color[w->a].g * w->i * w->v / w->iteration_max  \
				, w->color[w->a].b * w->i * w->v / w->iteration_max);
	}
}

void	mandelbrot(t_win *w)
{
	w->y = 0 - w->yoffset;
	while (w->y < w->winsy - w->yoffset)
	{
		w->x = 0 - w->xoffset;
		while (w->x < w->winsx - w->xoffset)
		{
			w->cr = w->x / (w->winsx / (w->xmax - w->xmin)) + w->xmin;
			w->ci = w->y / (w->winsx / (w->ymax - w->ymin)) + w->ymin;
			w->zr = 0;
			w->zi = 0;
			trace(w);
			w->x++;
		}
		w->y++;
	}
}
