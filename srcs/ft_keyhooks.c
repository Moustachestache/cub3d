/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:30:38 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/02 15:26:58 by mjochum          ###   ########.fr       */
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
		ft_update_angle(&vars->player->angle, 5, vars);
	else if (keycode == 100)
		ft_update_angle(&vars->player->angle, -5, vars);
	ft_render(vars);
	return (0);
}
