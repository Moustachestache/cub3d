/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:28:47 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/24 12:15:01 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_get_player_vector(char c)
{
	if (c == 'N')
		return (90);
	if (c == 'E')
		return (0);
	if (c == 'S')
		return (270);
	if (c == 'W')
		return (180);
	return (0);
}

static void	ft_init_dir(t_vars *vars, char c)
{
	if (c == 'E' || c == 'W')
	{
		vars->camera->dir[0] = 0;
		if (c == 'E')
			vars->camera->dir[1] = 1;
		else
			vars->camera->dir[1] = -1;
		if (c == 'E')
			vars->camera->plane[0] = 0.66;
		else
			vars->camera->plane[0] = -0.66;
		vars->camera->plane[1] = 0;
	}
	else
	{
		if (c == 'S')
			vars->camera->dir[0]= 1;
		else
			vars->camera->dir[0] = -1;
		if (c == 'S')
			vars->camera->plane[1] = -0.66;
		else
			vars->camera->plane[1] = 0.66;
		vars->camera->dir[1] = 0;
		vars->camera->plane[0] = 0;
	}
}

void	ft_player_init(int x, int y, char mapinfo, t_vars *vars)
{
	vars->player->start = mapinfo;
	vars->player->angle = ft_get_player_vector(mapinfo);
	ft_init_dir(vars, mapinfo);
	vars->player->step = 0.2;
	vars->player->xpos = (float)x + 0.5;
	vars->player->ypos = (float)y + 0.5;
}
