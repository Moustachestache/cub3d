/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:27:29 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/12 16:54:28 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_init_dir(t_camera *camera, int angle)
{
	float	radian_angle;
	float	vector_len;

	radian_angle = angle * (M_PI / 180.0);
	camera->dirX = cos(radian_angle);
	camera->dirY = sin(radian_angle);
	vector_len = sqrt(camera->dirX * camera->dirX + camera->dirY * camera->dirY);
	camera->dirX /= vector_len;
	camera->dirY /= vector_len;
}

static void	ft_set_stepX(t_player *player, t_camera *camera)
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

static void	ft_set_stepY(t_player *player, t_camera *camera)
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

	ft_init_dir(camera, vars->player->angle);
	camera->planeX = -camera->dirY * 0.6;
	camera->planeY = camera->dirX * 0.6;
	i = -1;
	while (++i < W_WIDTH)
	{
		camera->cameraX = 2 * i / W_WIDTH - 1;
		camera->ray_dirX = camera->dirX + camera->planeX * camera->cameraX;
		camera->ray_dirY = camera->dirY + camera->planeY * camera->cameraX;
		camera->mapX = (int)vars->player->xpos / CELL_SIZE;
		camera->mapY = (int)vars->player->ypos / CELL_SIZE;
		if (camera->ray_dirX == 0)
			camera->delta_distX = 1e30;
		else
			camera->delta_distX = fabs(1 / camera->ray_dirX);
		if (camera->ray_dirY == 0)
			camera->delta_distY = 1e30;
		else
			camera->delta_distY = fabs(1 / camera->ray_dirY);
		ft_set_stepX(vars->player, camera);
		ft_set_stepY(vars->player, camera);
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
			if (vars->mapdata->map[camera->mapY][camera->mapX] > 0)
				camera->hit = 1;
		}
		if (camera->side == 0)
		{
			camera->wall_dist = camera->side_distX - camera->delta_distX;
			camera->intersect = fmod(vars->player->xpos + camera->wall_dist * camera->ray_dirX, 1.0);
			camera->intersect = floorf(camera->intersect * 128.0);
		}

		else
		{
			camera->wall_dist = camera->side_distY - camera->delta_distY;
			camera->intersect = fmod(vars->player->ypos + camera->wall_dist * camera->ray_dirY, 1.0);
			camera->intersect = floorf(camera->intersect * 128.0);
		}
		// here
			camera->wall_dist = fabs(camera->wall_dist);
		ft_drawslice(i, camera, NULL, vars);
	}
}
