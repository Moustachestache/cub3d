/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:27:29 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/17 21:07:19 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int ft_check_hit(t_vars *vars, t_camera *camera,  float ray[2], t_map *mapdata)
{
	(void) vars;
	if (camera->side_dist[0] < camera->side_dist[1])
	{
		camera->side_dist[0] += camera->delta_dist[0];
		camera->mapX += camera->stepX;
		if (ray[0] > 0)
			camera->side = 'N';
		else
			camera->side = 'S';
	}
	else
	{
		camera->side_dist[1] += camera->delta_dist[1];
		camera->mapY += camera->stepY;
		if (ray[1] > 0)
			camera->side = 'E';
		else
			camera->side = 'W';
	}
	return (mapdata->map[1][0] == 1);
}

static void ft_init_camera(t_vars *vars, t_camera *camera, float ray[2])
{
	camera->delta_dist[0] = fabs(1.0 / ray[0]);
	camera->delta_dist[1] = fabs(1.0 / ray[1]);
	camera->mapX = floor(vars->player->xpos);
	camera->mapY = floor(vars->player->ypos);
	if (ray[0] < 0)
		camera->stepX = -1;
	else
		camera->stepX = 1;
	if (ray[1] < 0)
		camera->stepY = -1;
	else
		camera->stepY = 1;
        if (ray[0] < 0)
                camera->side_dist[0] = (vars->player->xpos - camera->mapX)
			* camera->delta_dist[0];
	else
	        camera->side_dist[0] = (camera->mapX + 1.0 - vars->player->xpos)
			* camera->delta_dist[0];
	if (ray[1] < 0)
		camera->side_dist[1] = (vars->player->ypos - camera->mapY)
			* camera->delta_dist[1];
	else
		camera->side_dist[1] = (camera->mapY + 1.0 - vars->player->ypos)
		       * camera->delta_dist[1];
}

static void ft_raycast(t_vars *vars, t_camera *camera, int i, float ray[2])
{
	(void) vars;
	camera->hit = 0;
        ft_init_camera(vars, camera, ray);
	while (!camera->hit)
	{
		camera->hit = ft_check_hit(vars, camera, ray, vars->mapdata);
		if (camera->side == 'N' || camera->side == 'S')
			camera->wall_dist = (camera->mapX - vars->player->xpos
					+ (1 - camera->stepX) / 2) / ray[0];
		else
			camera->wall_dist = (camera->mapY - vars->player->ypos
					+ (1 - camera->stepY) / 2) / ray[1];
		if (camera->side == 'N' || camera->side == 'S')
			camera->intersect = vars->player->ypos + camera->wall_dist * ray[1];
		else
			camera->intersect = vars->player->xpos + camera->wall_dist * ray[0];
		camera->intersect -= floor(camera->intersect);
		ft_drawslice(i, camera, NULL, vars);
	}
}

static void ft_rotate(t_camera *camera, int angle)
{
	float	rad_angle;
	float	tmp;

	rad_angle = angle * (M_PI / 180.0);
	tmp = camera->dir[0];
	camera->dir[0] = tmp * cos(rad_angle) - camera->dir[1] * sin(rad_angle);
	camera->dir[1] = tmp * sin(rad_angle) + camera->dir[1] * cos(rad_angle);
	tmp = camera->plane[0];
	camera->plane[0] = tmp * cos(rad_angle) - camera->plane[1] * sin(rad_angle);
	camera->plane[1] = tmp * sin(rad_angle) + camera->plane[1] * cos(rad_angle);
}	

void ft_draw_rays(t_vars *vars)
{
	int	i;
	float	cameraX;
	float	ray[2];

	i = 0;
	ft_rotate(vars->camera, vars->player->angle);
	while (i < W_WIDTH)
	{
		cameraX = 2.0 * i / W_WIDTH - 1.0;
		ray[0] = vars->camera->dir[0] + vars->camera->plane[0] * cameraX;
		ray[1] = vars->camera->dir[1] + vars->camera->plane[1] * cameraX;
		ft_raycast(vars, vars->camera, i++, ray);
	}
}
