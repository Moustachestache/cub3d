/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:00:55 by mjochum           #+#    #+#             */
/*   Updated: 2024/01/28 17:15:46 by mjochum          ###   ########.fr       */
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
typedef struct s_texture t_texture;

typedef struct s_image {
	void				*image;
	char				*addr;
	int					bpp;
	int					len;
	int					endian;
}						t_image;

typedef struct s_texture {
	void		*image;
	int			width;
	int			height;
}				t_texture;

typedef struct s_vars {
	int					fd_map;
	int					interface_toggle;
	void				*mlx;
	void				*mlx_win;
	t_image				*buffer;
	t_map				*mapdata;
	t_player			*player;
	t_camera			*camera;
	void			*logo;

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
	float				step;
	int					angle;
	float				xpos;
	float				ypos;
}						t_player;

typedef struct s_camera {
	int					hit;
	int					side;
	int					stepX;
	int					stepY;
	int					mapX;
	int					mapY;
	float				dirX;
	float				dirY;
	float				planeX;
	float				planeY;
	float				cameraX;
	float				ray_dirX;
	float				ray_dirY;
	float				wall_dist;
	float				side_distX;
	float				side_distY;
	float				delta_distX;
	float				delta_distY;
}						t_camera;

typedef struct s_pixel {
	int					x;
	int					y;
	unsigned int		colour;
}						t_pixel;

#endif
