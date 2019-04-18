/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:55:19 by bbataini          #+#    #+#             */
/*   Updated: 2018/09/14 15:27:06 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	init_julia(t_win *w)
{
	w->fractal = JULIA;
	w->iteration_max = 75;
	w->iteration_maxi = 220;
	w->xmin = -1;
	w->xmax = 1;
	w->ymin = -1.2;
	w->ymax = 1.2;
	w->xoffset = 0;
	w->yoffset = 0;
	w->v = 1;
	w->c = 1;
	w->a = 0;
	ft_putstr("\n**** Fractal de Julia ****\n\n\n");
	ft_putstr("Couleur : '9' '0' '-' '=' 'a' 's' \n");
	ft_putstr("Deplacement : Fleche\nIterations : 'o' / 'p' \n ");
	ft_putstr("Zoom : souris\n");
}

void	julia(t_win *w)
{
	w->y = 0 - w->yoffset;
	while (w->y < w->winsy - w->yoffset)
	{
		w->x = 0 - w->xoffset;
		while (w->x < w->winsx - w->xoffset)
		{
			w->cr = 0.285;
			w->ci = 0.01;
			w->zr = w->x / (w->winsx / (w->xmax - w->xmin)) + w->xmin;
			w->zi = w->y / (w->winsx / (w->ymax - w->ymin)) + w->ymin;
			trace(w);
			w->x++;
		}
		w->y++;
	}
}
