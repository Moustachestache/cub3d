/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:27:29 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/01 12:26:22 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "../cub3d.h"
int		ft_iswall(int x, int y, t_map *map)
{
	return (0);
}

float	ft_hdist(t_player camera, t_vars *vars)
{
	float	hdist;
	float	x;
	float	y;
	float	retval;

	hdist = 0;
	while (ft_iswall(x, y, vars->mapdata) == 0)
	{
		retval += hdist;
	}
	return (retval);
}

void	ft_draw_slice(t_player camera, t_vars *vars)
{
	float	hdist;
	float	vdist;

	hdist = ft_hdist(t_player, vars);
}

void	ft_raycast(t_vars *vars)
{
	t_player	camera;
	float		angleincrement;
	int			i;
	i = 0;

	camera = (t_player){0, 0, vars->player->angle, vars->player->xpos, vars->player->ypos};
	ft_update_angle(&camera.angle, FOV / 2, vars);
	angleincrement = FOV / W_WIDTH;
	while (i < W_WIDTH)
	{
			ft_draw_slice(camera, vars);
			camera.angle -= angleincrement;
	}
}*/
