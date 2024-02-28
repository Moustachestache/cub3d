/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:30:38 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/28 15:21:47 by mjochum          ###   ########.fr       */
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

static void	ft_rotate(t_vars *vars, t_camera *camera, int angle)
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
	ft_update_angle(&vars->player->angle, angle, vars);
}

//	check if moveable or no
static void	ft_moveplayer(float angle, float value, t_vars *vars)
{
	ft_transform_player(&vars->player->xpos, \
		&vars->player->ypos, \
		value, \
		angle);
}

int	ft_mouse(int x, int y, void *param)
{
	t_vars		*vars;
	static int	oldx;
	float		rotation;

	(void) y;
	if (x == W_WIDTH / 2)
		return (0);
	vars = param;
	if (oldx - x < 0)
		rotation = -1;
	else
		rotation = 1;
	oldx = x;
	ft_rotate(vars, vars->camera, rotation);
	mlx_mouse_move(vars->mlx, vars->mlx_win, W_WIDTH / 2, W_HEIGHT / 2);
	return (1);
}

static void	ft_opendoor(t_map *mapdata)
{
	if (mapdata->map[9][8] == '0')
		mapdata->map[9][8] = '1';
	else
		mapdata->map[9][8] = '0';
}

int	ft_keyhook(int keycode, t_vars *vars)
{
	if (keycode == 105)
		ft_key_toggle(&vars->interface_toggle);
	else if (keycode == 65307)
		ft_exit(EXIT_SUCCESS, vars);
	else if (keycode == 119 || keycode == 65362 || keycode == 122)
		ft_moveplayer(vars->player->angle, vars->player->step, vars);
	else if (keycode == 115 || keycode == 65364)
		ft_moveplayer(vars->player->angle, -vars->player->step, vars);
	else if (keycode == 100)
		ft_moveplayer(vars->player->angle + 90, -vars->player->step, vars);
	else if (keycode == 97 || keycode ==  113)
		ft_moveplayer(vars->player->angle - 90, -vars->player->step, vars);
	else if (keycode == 65361)
		ft_rotate(vars, vars->camera, 5);
	else if (keycode == 65363)
		ft_rotate(vars, vars->camera, -5);
	else if (keycode == 32)
		ft_opendoor(vars->mapdata);
	return (0);
}
