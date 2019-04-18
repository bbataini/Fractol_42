/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 17:34:21 by bbataini          #+#    #+#             */
/*   Updated: 2018/09/04 16:49:30 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	fractal(t_win *w)
{
	if (w->fractal == 1)
		mandelbrot(w);
	if (w->fractal == 2)
		julia(w);
	if (w->fractal == 3)
		tree(w, 29.85, w->start, w->iteration_max);
}
