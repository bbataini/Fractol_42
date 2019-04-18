/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:01:51 by bbataini          #+#    #+#             */
/*   Updated: 2018/09/04 16:49:33 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	init_tree(t_win *w)
{
	w->angle = 0.3;
	w->start.x = w->winsx / 2;
	w->start.y = w->winsy - 20;
	w->ang1 = 16;
	w->ang2 = 16;
	w->xoffset = 0;
	w->yoffset = 0;
	w->zoomt = 3;
	w->fractal = TREE;
	w->iteration_max = 10;
	w->iteration_maxi = 20;
	ft_putstr("\n**** Fractal arbre ****\n\n\n");
	ft_putstr("Angle : 'z' 'x' 'c' 'v'\n");
	ft_putstr("Deplacement : Fleche\nIterations : 'o' / 'p' \n");
	ft_putstr("Zoom : souris\n");
}

void	pxl_tree_img(t_win *w, char r, char g, char b)
{
	int x;
	int y;

	x = w->tx + w->xoffset;
	y = w->ty + w->yoffset;
	if (x < w->winsx && y < w->winsy && x > 0 && y > 0)
	{
		x = x * w->bpp;
		y = y * w->img->sizeline;
		w->img->data[x + y] = r;
		w->img->data[x + 1 + y] = g;
		w->img->data[x + 2 + y] = b;
	}
}

void	putl(t_win *w, t_point start, t_point end, int iter)
{
	int		dd;
	double	dx;
	double	dy;

	w->tx = start.x;
	w->ty = start.y;
	iter++;
	dx = end.x - start.x;
	dy = end.y - start.y;
	dd = sqrt((dx * dx) + (dy * dy));
	dx = dx / dd;
	dy = dy / dd;
	while (dd-- >= 0)
	{
		if (w->tx < w->winsx - w->xoffset && w->tx > 0 - w->xoffset &&
				w->ty > 0 - w->yoffset && w->ty < w->winsy - w->yoffset)
		{
			pxl_tree_img(w, 0 \
					, 51 + w->iteration_max / iter * 0.5 \
					, 102 * iter / w->iteration_max);
		}
		w->tx += dx;
		w->ty += dy;
	}
}

void	tree(t_win *w, double angle, t_point start, int iter)
{
	t_point end;

	if (iter > 0)
	{
		end.x = start.x + (cos(angle) * iter * 2 * w->zoomt);
		end.y = start.y + (sin(angle) * iter * 3 * w->zoomt);
		iter--;
		putl(w, start, end, iter);
		tree(w, angle - (M_PI / w->ang1), end, iter);
		tree(w, angle + (M_PI / w->ang2), end, iter);
	}
}
