/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:41:37 by bbataini          #+#    #+#             */
/*   Updated: 2018/09/14 14:33:38 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define MANDELBROT 1
# define JULIA 2
# define TREE 3
# define K_SPACE 49
# define K_Z 6
# define K_X 7
# define K_C 8
# define K_V 9
# define K_1 18
# define K_2 19
# define K_3 20
# define K_9 25
# define K_0 29
# define K_O 31
# define K_P 35
# define K_ESC 53
# define K_MINUS 27
# define K_EGUAL 24
# define K_A 0
# define K_S 1
# define K_ARW_UP 126
# define K_ARW_DWN 125
# define K_ARW_RIGHT 124
# define K_ARW_LEFT 123
# define M_L 1
# define M_R 2
# define M_SCROLL_UP 4
# define M_SCROLL_DWN 5

typedef struct		s_color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}					t_color;

typedef struct		s_img
{
	void	*image;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
}					t_image;

typedef struct		s_point
{
	double x;
	double y;
}					t_point;

typedef struct		s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		*img;
	t_color		*color;
	t_point		start;
	int			fractal;
	int			x;
	int			y;
	double		cr;
	double		ci;
	double		zr;
	double		zi;
	float		ji;
	int			i;
	int			iteration_max;
	int			iteration_maxi;
	double		xmin;
	double		xmax;
	double		ymax;
	double		ymin;
	double		tmp;
	int			zoomx;
	int			zoomy;
	int			zoom;
	int			zoomt;
	int			pause;
	int			c;
	int			a;
	int			winsx;
	int			winsy;
	int			v;
	double		tx;
	double		ty;
	int			bpp;
	int			m_x;
	int			m_y;
	int			tmpx;
	int			tmpy;
	int			n;
	int			side;
	double		angle;
	int			ang1;
	int			ang2;
	int			xoffset;
	int			yoffset;
	int			s_l;
}					t_win;

t_win				init_win(t_win *w);
void				fractal(t_win *w);
void				pxl_to_img(t_win *w, char r, char g, char b);
void				mandelbrot(t_win *w);
t_image				*newimg(t_win *w);
int					init_mandelbrot(t_win *w);
void				ft_zoom(t_win *w, int button);
void				trace(t_win *w);
void				init_julia(t_win *w);
void				julia(t_win *w);
void				init_tree(t_win *w);
void				tree(t_win *w, double angle, t_point start, int iter);
void				line(int xa, int ya, int xb, int yb, t_win *w);
void				text(int key, t_win *w);

#endif
