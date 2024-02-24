/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:27:29 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/24 12:06:13 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_check_hit(t_vars *vars, t_camera *camera, \
	float ray[2], t_map *mapdata)
{
	(void) vars;
	(void) mapdata;
	if (camera->side_dist[0] < camera->side_dist[1])
	{
		camera->side_dist[0] += camera->delta_dist[0];
		camera->mapY += camera->stepY;
		if (ray[0] > 0)
			camera->side = 'N';
		else
			camera->side = 'S';
	}
	else
	{
		camera->side_dist[1] += camera->delta_dist[1];
		camera->mapX += camera->stepX;
		if (ray[1] > 0)
			camera->side = 'E';
		else
			camera->side = 'W';
	}
	if (mapdata->map[camera->mapY][camera->mapX] == '1')
		return (1);
	else
		return (0);
}

static void	ft_init_camera(t_vars *vars, t_camera *camera, float ray[2])
{
	camera->delta_dist[0] = fabs(1.0 / ray[0]);
	camera->delta_dist[1] = fabs(1.0 / ray[1]);
	camera->mapX = floor(vars->player->xpos);
	camera->mapY = floor(vars->player->ypos);
	if (ray[0] < 0)
		camera->stepY = -1;
	else
		camera->stepY = 1;
	if (ray[1] < 0)
		camera->stepX = -1;
	else
		camera->stepX = 1;
	if (ray[0] < 0)
		camera->side_dist[0] = (vars->player->ypos - camera->mapY) \
			* camera->delta_dist[0];
	else
		camera->side_dist[0] = (camera->mapY + 1.0 - vars->player->ypos) \
			* camera->delta_dist[0];
	if (ray[1] < 0)
		camera->side_dist[1] = (vars->player->xpos - camera->mapX) \
			* camera->delta_dist[1];
	else
		camera->side_dist[1] = (camera->mapX + 1.0 - vars->player->xpos) \
			* camera->delta_dist[1];
}

static void	ft_raycast(t_vars *vars, t_camera *camera, int i, float ray[2])
{
	(void) vars;
	camera->hit = 0;
	ft_init_camera(vars, camera, ray);
	while (camera->hit == 0)
	{
		camera->hit = ft_check_hit(vars, camera, ray, vars->mapdata);
	}
	if (camera->side == 'N' || camera->side == 'S')
		camera->wall_dist = (camera->mapY - vars->player->ypos
				+ (1 - camera->stepY) / 2) / ray[0];
	else
		camera->wall_dist = (camera->mapX - vars->player->xpos
				+ (1 - camera->stepX) / 2) / ray[1];
	if (camera->side == 'N' || camera->side == 'S')
		camera->intersect = vars->player->xpos + camera->wall_dist * ray[1];
	else
		camera->intersect = vars->player->ypos + camera->wall_dist * ray[0];
	camera->intersect -= floor(camera->intersect);
	ft_drawslice(i, camera, NULL, vars);
}

void	ft_draw_rays(t_vars *vars)
{
	int		i;
	float	camerax;
	float	ray[2];

	i = 0;
	while (i < W_WIDTH)
	{
		camerax = 2.0 * i / W_WIDTH - 1.0;
		ray[0] = vars->camera->dir[0] + vars->camera->plane[0] * camerax;
		ray[1] = vars->camera->dir[1] + vars->camera->plane[1] * camerax;
		ft_raycast(vars, vars->camera, i, ray);
		i++;
	}
}
