/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:27:29 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/05 14:28:10 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	ft_init_dirX(int angle)
{
	float radian_angle;

	radian_angle = angle * (M_PI / 180.0);
	return (cos(radian_angle));
}

float ft_init_dirY(int angle)
{
	float radian_angle;

	radian_angle = angle * (M_PI / 180.0);
	return (sin(radian_angle));
}

void	ft_set_stepX(t_player *player, t_camera *camera)
{
	if (camera->ray_dirX < 0)
	{
		camera->stepX = -1;
		camera->side_distX = (player->xpos - camera->mapX) * camera->delta_distX;
	}
	else
	{
		camera->stepX = 1;
		camera->side_distX = (camera->mapX + 1.0 - player->xpos) * camera->delta_distX;
	}
}

void	ft_set_stepY(t_player *player, t_camera *camera)
{
	if (camera->ray_dirY < 0)
	{
		camera->stepY = -1;
		camera->side_distY = (player->ypos - camera->mapY) * camera->delta_distY;
	}
	else
	{
		camera->stepY = 1;
		camera->side_distY = (camera->mapY + 1.0 - player->ypos) * camera->delta_distY;
	}
}

void	ft_raycast(t_vars *vars, t_camera *camera)
{
	int		i;

	camera->dirX = ft_init_dirX(vars->player->angle);
	camera->dirY = ft_init_dirY(vars->player->angle);
	if (camera->dirX == 0)
	{
		camera->planeX = 0.6;
		camera->planeY = 0;
	}
	if (camera->dirY == 0)
	{
		camera->planeX = 0;
		camera->planeY = 0.6;
	}
	i = 0;
	while (i++ < W_WIDTH)
	{
		camera->cameraX = 2 * i / W_WIDTH - 1;
		camera->ray_dirX = camera->dirX + camera->planeX * camera->cameraX;
		camera->ray_dirY = camera->dirY + camera->dirY * camera->cameraX;
		camera->mapX = (int)vars->player->xpos;
		camera->mapY = (int)vars->player->ypos;
		if (camera->ray_dirX == 0)
			camera->delta_distX = 1e30;
		else
			camera->delta_distX = fabs(1 / camera->ray_dirX);
		if (camera->ray_dirY == 0)
			camera->delta_distY = 1e30;
		else
			camera->delta_distY = fabs(1 / camera->ray_dirY);
		camera->stepX = ft_set_stepX(vars->player, camera);
		camera->stepY = ft_set_stepY(vars->player, camera);
		while (camera->hit == 0)
		{
			if (camera->side_distX < camera->side_distY)
			{
				camera->side_distX += camera->delta_distX;
				camera->mapX += camera->stepX;
				camera->side = 0;
			}
			else
			{
				camera->side_distY += camera->delta_distY;
				camera->mapY += camera->stepY;
				camera->side = 1;
			}
			if (vars->mapdata[camera->mapX][camera->mapY] > 0)
				camera->hit = 1;
		}
		if (camera->side == 0)
			camera->wall_dist = camera->side_distX - camera->delta_distX;
		else
			camera->wall_dist = camera->side_distY - camera->delta_distY;
		printf("%f", camera->wall_dist);
		// here
		ft_drawslice(i, camera, NULL, vars);
	}
}
