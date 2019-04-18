/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:37:54 by bbataini          #+#    #+#             */
/*   Updated: 2018/09/04 15:56:36 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		deal_key(int key, t_win *w)
{
	if (key == K_SPACE)
		w->pause = 0 - w->pause;
	if (key == K_ESC || key == K_O || key == K_P)
		text(key, w);
	if (key == K_Z)
		w->ang1++;
	if (key == K_X)
		w->ang1--;
	if (key == K_C)
		w->ang2++;
	if (key == K_V)
		w->ang2--;
	if (key == K_MINUS && w->c > 0)
		w->c--;
	if (key == K_EGUAL && w->c < 8)
		w->c++;
	if (key == K_A && w->a > 0)
		w->a--;
	if (key == K_S && w->a < 9)
		w->a++;
	w->img = newimg(w);
	fractal(w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img->image, 0, 0);
	return (0);
}

int		gere_mouse(int b, int x, int y, t_win *w)
{
	if ((b == M_L || b == M_SCROLL_UP || b == M_R || b == M_SCROLL_DWN)
			&& w->fractal != TREE)
	{
		w->m_x = x;
		w->m_y = y;
		ft_zoom(w, b);
	}
	if (b == M_L || b == M_SCROLL_UP)
		w->zoomt++;
	if (b == M_R || b == M_SCROLL_DWN)
		w->zoomt--;
	w->img = newimg(w);
	fractal(w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img->image, 0, 0);
	return (b);
}

int		mousep(int x, int y, t_win *w)
{
	if (x < w->winsx && y < w->winsx && w->fractal == 2 && w->pause == -1)
	{
		w->ji = ((double)x + (double)y) / 1600;
	}
	else if (w->pause == -1)
		w->ji = 0;
	w->img = newimg(w);
	fractal(w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img->image, 0, 0);
	return (0);
}

int		key_event(int key, t_win *w)
{
	if (key == K_2)
		init_julia(w);
	if (key == K_1)
		init_mandelbrot(w);
	if (key == K_3)
		init_tree(w);
	if (key == K_9 && w->v > 0)
		w->v--;
	if (key == K_0)
		w->v++;
	if (key == K_ARW_UP)
		w->yoffset -= 15;
	if (key == K_ARW_DWN)
		w->yoffset += 15;
	if (key == K_ARW_LEFT)
		w->xoffset -= 15;
	if (key == K_ARW_RIGHT)
		w->xoffset += 15;
	w->img = newimg(w);
	fractal(w);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img->image, 0, 0);
	return (key);
}

int		main(int ac, char **av)
{
	t_win	w;

	if (ac != 2)
		text(42, &w);
	if (0 == ft_strcmp(av[1], "mandelbrot"))
		init_mandelbrot(&w);
	if (0 == ft_strcmp(av[1], "julia"))
		init_julia(&w);
	if (0 == ft_strcmp(av[1], "tree"))
		init_tree(&w);
	if (w.fractal == 0)
		text(42, &w);
	w = init_win(&w);
	fractal(&w);
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr, w.img->image, 0, 0);
	mlx_mouse_hook(w.win_ptr, gere_mouse, &w);
	mlx_hook(w.win_ptr, 6, 1L << 0, &mousep, &w);
	mlx_hook(w.win_ptr, 2, 1L << 0, &key_event, &w);
	mlx_key_hook(w.win_ptr, deal_key, &w);
	mlx_loop(w.mlx_ptr);
	return (0);
}
