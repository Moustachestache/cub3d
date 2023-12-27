# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjochum <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 09:36:26 by mjochum           #+#    #+#              #
#    Updated: 2023/12/27 09:53:19 by mjochum          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

SRCS		=	cub3d.c $(shell ls srcs/*.c)

OBJS		=	$(SRCS:.c=.o)

CC			=	clang

CFLAGS		=	-Wall -Werror -Wextra

NAME:			$(OBJS)
				$(CC) $(CFLAGS) mlx/libmlx_Linux.a -lXext -lX11 -lm -lz $(OBJS) -o $(NAME)

all:			$(NAME)

clean:			rm -f $(OBJS)
