/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:41:03 by bbataini          #+#    #+#             */
/*   Updated: 2018/09/14 14:29:45 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_color		*init_color(void)
{
	static t_color color[9] = {
		{255, 0, 0},
		{248, 248, 121},
		{0, 255, 0},
		{79, 248, 87},
		{0, 191, 255},
		{128, 128, 128},
		{255, 255, 255},
		{255, 0, 242},
		{21, 255, 255}
	};

	return (color);
}

t_image		*newimg(t_win *w)
{
	t_image	*img;

	free(w->img);
	if ((img = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	img->image = mlx_new_image(w->mlx_ptr, w->winsx, w->winsy);
	img->data = mlx_get_data_addr(img->image,
	&img->bpp, &img->sizeline, &img->endian);
	w->bpp = img->bpp / 8;
	return (img);
}

t_win		init_win(t_win *w)
{
	w->winsx = 800;
	w->winsy = 800;
	w->mlx_ptr = mlx_init();
	w->win_ptr = mlx_new_window(w->mlx_ptr, w->winsx, w->winsy, "mlx 42");
	w->c = 1;
	w->pause = -1;
	w->color = init_color();
	w->img = newimg(w);
	return (*w);
}
