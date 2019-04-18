# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbataini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/16 16:24:23 by bbataini          #+#    #+#              #
#    Updated: 2018/09/03 17:53:14 by bbataini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_LIST = main.c \
			init_win.c \
			mandelbrot.c \
			fractal.c \
			zoom.c \
			julia.c \
			tree.c \
			text.c \

LIB = libft/libft.a \
	  minilibx_macos/libmlx.a \

CLIB = libft/ \
	   minilibx_macos/ \

INC = fdf.h \

FAFO = -framework AppKit -framework OpenGL 

all: $(NAME)
	make -C libft/
	make -C minilibx_macos/
	$(CC) $(CFLAGS) $(SRCS_LIST) $(LIB) -I $(INC) $(FAFO)
	mv a.out fractol

clean:
	make -C libft/ clean
	make -C minilibx_macos/ clean

fclean: clean
		make fclean -C libft/
		rm -f fractol

re: fclean all
