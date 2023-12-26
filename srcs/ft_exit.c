/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:31:50 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/26 16:03:34 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//	cleans memory and exits

void	ft_free_map(t_map *mapdata)
{
	static int	i = 0;

	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->ea)
		free(map->ea);
	if (map->we)
		free(map->we);
	while (mapdata->map[i])
	{
		free(mapdata->map[i]);
		i++;
	}
	free(mapdata);
}

void	ft_exit(int exit_value, t_vars *vars)
{
	ft_free_map(vars->mapdata);
	if (vars->fd_map > 0 && close(vars->fd_map < 0))
			ft_perror("error", -1);
	if (vars)
		free(vars);
	exit(exit_value);
}
