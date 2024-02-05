/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:00:55 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/05 14:28:56 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "cub3d.h"

typedef struct s_vars		t_vars;
typedef struct s_map		t_map;
typedef struct s_player		t_player;
typedef struct s_pixel		t_pixel;
typedef struct s_image		t_image;
typedef struct s_texture	t_texture;
typedef struct s_camera 	t_camera;

typedef struct s_image
{
	void				*image;
	char				*addr;
	int					bpp;
	int					len;
	int					endian;
	int					height;
	int					width;
}						t_image;

typedef struct s_vars
{
	int					fd_map;
	int					interface_toggle;
	void				*mlx;
	void				*mlx_win;
	t_image				*buffer;
	t_map				*mapdata;
	t_player			*player;
	t_image				background;
	t_image				logo;
	t_image				minimap;
	t_camera			*camera;
}						t_vars;

typedef struct s_map
{
	int					height;
	int					width;
	unsigned int		floor;
	unsigned int		ceiling;
	char				*no;
	char				*so;
	char				*ea;
	char				*we;
	char				*door;
	char				*sprite;
	char				**map;
	t_image				*texture;
}						t_map;

typedef struct s_player
{
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
	float				intersect;
}						t_camera;

typedef struct s_pixel {
	int					x;
	int					y;
	unsigned int		colour;
}						t_pixel;

#endif
