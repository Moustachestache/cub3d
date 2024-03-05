# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjochum <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 09:36:26 by mjochum           #+#    #+#              #
#    Updated: 2024/02/29 14:47:47 by mjochum          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

SRCS		=	cub3d.c \
srcs/ft_atoi.c srcs/ft_free_split.c srcs/ft_keyhooks.c srcs/ft_split.c \
srcs/ft_bzero.c srcs/ft_image_management.c srcs/ft_map_validation.c srcs/ft_strdup.c \
srcs/ft_calloc.c srcs/ft_img_flush.c srcs/ft_memcpy.c srcs/ft_strncmp.c \
srcs/ft_darken.c srcs/ft_img_pix_put.c srcs/ft_memset.c srcs/ft_transform.c \
srcs/ft_deg_to_rad.c srcs/ft_init_player.c srcs/ft_parse_map.c srcs/ft_update_vector.c \
srcs/ft_drawline.c srcs/ft_init_textures.c srcs/ft_perror.c srcs/ft_validate_mapinfo.c \
srcs/ft_drawplayer.c srcs/ft_init_vars.c srcs/ft_put_img.c srcs/ft_write_toscreen.c \
srcs/ft_drawslice.c srcs/ft_isposix.c srcs/ft_raycast.c srcs/get_next_line.c \
srcs/ft_exit.c srcs/ft_isspace.c srcs/ft_render_minimap.c srcs/get_next_line_utils.c \
srcs/ft_frame.c srcs/ft_init_sprite.c srcs/ft_itoa.c srcs/ft_render_graphfps.c
 

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
