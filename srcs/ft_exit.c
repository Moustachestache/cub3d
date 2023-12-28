/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:31:50 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/27 13:17:17 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//	cleans memory and exits

static void	ft_free_map(t_map *mapdata)
{
	static int	i = 0;

	if (mapdata->no)
		free(mapdata->no);
	if (mapdata->so)
		free(mapdata->so);
	if (mapdata->ea)
		free(mapdata->ea);
	if (mapdata->we)
		free(mapdata->we);
	while (mapdata->map[i])
	{
		free(mapdata->map[i]);
		i++;
	}
	free(mapdata);
}

void	ft_exit(int exit_value, t_vars *vars)
{
	if (vars && vars->mapdata)
		ft_free_map(vars->mapdata);
	if (vars->fd_map > 0 && close(vars->fd_map < 0))
		ft_perror("error", -1);
	if (vars->player)
		free(vars->player);
	if (vars)
		free(vars);
	exit(exit_value);
}
