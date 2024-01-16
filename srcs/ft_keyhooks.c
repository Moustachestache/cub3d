/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:30:38 by mjochum           #+#    #+#             */
/*   Updated: 2024/01/16 13:48:47 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_keyhook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_exit(EXIT_SUCCESS, vars);
	else if (keycode == 119)	//up
		ft_transform_player(&vars->player->xpos, &vars->player->ypos, vars->player->step, vars->player->angle);
	else if (keycode == 115)	//down
		ft_transform_player(&vars->player->xpos, &vars->player->ypos, -(vars->player->step), vars->player->angle);
	else if (keycode == 97)		//left
		ft_update_vector(+5, vars);
	else if (keycode == 100)	//right
		ft_update_vector(-5, vars);
	ft_render(vars);
	return (0);
}
