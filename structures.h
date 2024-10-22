/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:00:55 by mjochum           #+#    #+#             */
/*   Updated: 2024/03/05 14:20:35 by mjochum          ###   ########.fr       */
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
typedef struct s_camera		t_camera;
typedef struct s_playerinfo	t_playerinfo;

typedef struct s_playerinfo
{
	float				*x;
	float				*y;
	float				increase;
	float				angle;
}						t_playerinfo;

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
	int					err;
	int					fd_map;
	int					interface_toggle;
	int					frame;
	int					fps[2];
	time_t				time;
	time_t				oldtime;
	void				*mlx;
	void				*mlx_win;
	t_map				*mapdata;
	t_player			*player;
	t_image				tdefault;
	t_image				background;
	t_image				logo;
	t_image				graphfps;
	t_image				minimap;
	t_image				*buffer;
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
	t_image				*stexture;
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

typedef struct s_camera
{
	int					hit;
	int					side;
	int					mapx;
	int					mapy;
	char				sprite;
	float				*depth;
	float				stepx;
	float				stepy;
	float				dir[2];
	float				plane[2];
	float				side_dist[2];
	float				delta_dist[2];
	float				wall_dist;
	float				intersect;
	float				sprite_intersect;
}						t_camera;

typedef struct s_pixel
{
	unsigned int		x;
	unsigned int		y;
	unsigned int		colour;
}						t_pixel;

#endif
