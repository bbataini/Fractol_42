/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 18:00:04 by bbataini          #+#    #+#             */
/*   Updated: 2018/09/14 15:27:02 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_zoom(t_win *w, int button)
{
	if (button == 1 || button == 4)
	{
		w->xmin *= 0.92;
		w->xmax *= 0.92;
		w->ymin *= 0.92;
		w->ymax *= 0.92;
		if (button == 1)
		{
			w->xoffset = (w->xoffset + 400 - w->m_x);
			w->yoffset = (w->yoffset + 400 - w->m_y);
		}
		w->xoffset /= 0.92;
		if (w->fractal == 1)
			w->xoffset += 19;
		w->yoffset /= 0.92;
	}
	else if (button == 2 || button == 5)
	{
		w->xmin *= 1.08;
		w->xmax *= 1.08;
		w->ymin *= 1.08;
		w->ymax *= 1.08;
		w->xoffset /= 1.08;
		w->yoffset /= 1.08;
	}
}
