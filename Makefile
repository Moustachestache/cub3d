# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjochum <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 09:36:26 by mjochum           #+#    #+#              #
#    Updated: 2023/12/31 14:22:47 by mjochum          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

SRCS		=	cub3d.c $(shell ls srcs/*.c) 

OBJS		=	$(SRCS:.c=.o) $(shell ls mlx/obj/*.o)

CC			=	clang

CFLAGS		=	-Wall -Werror -Wextra -gdwarf-4

MLX_FLAGS	=	-Lmlx -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

NAME:			$(OBJS)
				$(MAKE) -C mlx
				$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) mlx/libmlx_Linux.a -o $(NAME)

all:			$(NAME)

clean:			
				rm -f $(OBJS)
				$(MAKE) -C mlx clean

fclean:			clean
				rm -f $(NAME)

re:				fclean
				$(MAKE)
