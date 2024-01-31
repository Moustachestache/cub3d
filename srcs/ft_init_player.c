/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:28:47 by mjochum           #+#    #+#             */
/*   Updated: 2024/01/16 11:50:39 by mjochum          ###   ########.fr       */
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

void	ft_player_init(int x, int y, char mapinfo, t_vars *vars)
{
	vars->player->start = mapinfo;
	vars->player->angle = ft_get_player_vector(mapinfo);
	vars->player->step = 1.2;
	vars->player->xpos = (float)x * CELL_SIZE + 0.5;
	vars->player->ypos = (float)y * CELL_SIZE + 0.5;
}
