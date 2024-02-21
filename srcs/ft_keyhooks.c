/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:30:38 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/17 21:06:47 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_key_toggle(int *keyval)
{
	if (*keyval == 0)
		*keyval = 1;
	else
		*keyval = 0;
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

int	ft_keyhook(int keycode, t_vars *vars)
{
	if (keycode == 105)
		ft_key_toggle(&vars->interface_toggle);
	if (keycode == 65307)
		ft_exit(EXIT_SUCCESS, vars);
	else if (keycode == 119)
		ft_transform_player(&vars->player->xpos, &vars->player->ypos, \
			vars->player->step, vars->player->angle);
	else if (keycode == 115)
		ft_transform_player(&vars->player->xpos, &vars->player->ypos, \
			-(vars->player->step), vars->player->angle);
	else if (keycode == 97)
	{
		ft_update_angle(&vars->player->angle, 5, vars);
		ft_rotate(vars->camera, vars->player->angle);
	}
	else if (keycode == 100)
	{
		ft_update_angle(&vars->player->angle, -5, vars);
		ft_rotate(vars->camera, vars->player->angle);
	}
	ft_render(vars);
	return (0);
}
