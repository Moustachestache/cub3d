/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:00:55 by mjochum           #+#    #+#             */
/*   Updated: 2024/01/04 13:24:51 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_vars	t_vars;
typedef struct s_map	t_map;
typedef struct s_player t_player;
typedef struct s_pixel	t_pixel;
typedef struct s_image	t_image;

typedef struct s_image {
	void				*image;
	char				*addr;
	int					bpp;
	int					len;
	int					endian;
}						t_image;

typedef struct s_vars {
	int					fd_map;
	void				*mlx;
	void				*mlx_win;
	t_image				*buffer;
	t_map				*mapdata;
	t_player			*player;
}						t_vars;

typedef struct s_map {
	int					height;
	int					width;
	unsigned int		floor;
	unsigned int		ceiling;
	char				*no;
	char				*so;
	char				*ea;
	char				*we;
	char				**map;
}						t_map;

typedef struct s_player {
	char				start;
	int					xpos;
	int					ypos;
}						t_player;

typedef struct s_pixel {
	int					x;
	int					y;
	unsigned int		colour;
}						t_pixel;

#endif
