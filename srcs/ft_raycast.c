/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:27:29 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/28 15:28:53 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_check_hit(t_vars *vars, t_camera *camera, \
			float ray[2], t_map *mapdata, int i);

static void	ft_sprite_depth(t_vars *vars, t_camera *camera, float ray[2], int i)
{
	if (camera->side == 'N' || camera->side == 'S')
	{
		camera->depth[i] = (camera->mapy - vars->player->ypos
				+ (1 - camera->stepy) / 2) / ray[0];
		camera->sprite_intersect = vars->player->xpos + camera->depth[i]
			* ray[1];
	}
	else
	{
		camera->depth[i] = (camera->mapx - vars->player->xpos
				+ (1 - camera->stepx) / 2) / ray[1];
		camera->sprite_intersect = vars->player->ypos + camera->depth[i]
			* ray[0];
	}
	camera->sprite_intersect -= floor(camera->sprite_intersect);
}

static int	ft_check_hit(t_vars *vars, t_camera *camera, \
	float ray[2], t_map *mapdata, int i)
{
	(void) vars;
	(void) mapdata;
	(void) i;
	if (camera->side_dist[0] < camera->side_dist[1])
	{
		camera->side_dist[0] += camera->delta_dist[0];
		camera->mapy += camera->stepy;
		if (ray[0] > 0)
			camera->side = 'N';
		else
			camera->side = 'S';
	}
	else
	{
		camera->side_dist[1] += camera->delta_dist[1];
		camera->mapx += camera->stepx;
		if (ray[1] > 0)
			camera->side = 'E';
		else
			camera->side = 'W';
	}
	if (mapdata->map[camera->mapy][camera->mapx] == '1')
		return (1);
	else if (mapdata->map[camera->mapy][camera->mapx] == 'D'\
			|| mapdata->map[camera->mapy][camera->mapx] == 'd'\
			|| mapdata->map[camera->mapy][camera->mapx] == 's')
	{
		ft_sprite_depth(vars, camera, ray, i);
		return (0);
	}
	else
		return (0);
}

static void	ft_init_camera(t_vars *vars, t_camera *camera, float ray[2])
{
	camera->delta_dist[0] = fabs(1.0 / ray[0]);
	camera->delta_dist[1] = fabs(1.0 / ray[1]);
	camera->mapx = floor(vars->player->xpos);
	camera->mapy = floor(vars->player->ypos);
	if (ray[0] < 0)
		camera->stepy = -1;
	else
		camera->stepy = 1;
	if (ray[1] < 0)
		camera->stepx = -1;
	else
		camera->stepx = 1;
	if (ray[0] < 0)
		camera->side_dist[0] = (vars->player->ypos - camera->mapy) \
			* camera->delta_dist[0];
	else
		camera->side_dist[0] = (camera->mapy + 1.0 - vars->player->ypos) \
			* camera->delta_dist[0];
	if (ray[1] < 0)
		camera->side_dist[1] = (vars->player->xpos - camera->mapx) \
			* camera->delta_dist[1];
	else
		camera->side_dist[1] = (camera->mapx + 1.0 - vars->player->xpos) \
			* camera->delta_dist[1];
}

static void	ft_raycast(t_vars *vars, t_camera *camera, int i, float ray[2])
{
	(void) vars;
	camera->hit = 0;
	ft_init_camera(vars, camera, ray);
	while (camera->hit == 0)
	{
		camera->hit = ft_check_hit(vars, camera, ray, vars->mapdata, i);
	}
	if (camera->side == 'N' || camera->side == 'S')
		camera->wall_dist = (camera->mapy - vars->player->ypos
				+ (1 - camera->stepy) / 2) / ray[0];
	else
		camera->wall_dist = (camera->mapx - vars->player->xpos
				+ (1 - camera->stepx) / 2) / ray[1];
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
