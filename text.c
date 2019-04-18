/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 15:14:24 by bbataini          #+#    #+#             */
/*   Updated: 2018/09/04 14:24:15 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	text(int key, t_win *w)
{
	if (key == K_ESC || key == 42)
	{
		if (key == 42)
		{
			ft_putstr("Probleme argument\n 1) write mandelbrot\n");
			ft_putstr(" 2) write julia\n 3) write tree");
		}
		ft_putstr("\nfin du programe\n");
		exit(42);
	}
	if (key == K_P && w->iteration_max < w->iteration_maxi)
		w->iteration_max++;
	if (key == K_O && w->iteration_max > 0)
		w->iteration_max--;
	ft_putstr("\nNombre d'iterations : ");
	ft_putnbr(w->iteration_max);
}
