/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:31:50 by mjochum           #+#    #+#             */
/*   Updated: 2024/01/01 15:23:06 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_free_mlx(t_vars *vars)
{
	if (vars->mlx_win)
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

static void	ft_free_map(t_map *mapdata)
{
	if (mapdata->no)
		free(mapdata->no);
	if (mapdata->so)
		free(mapdata->so);
	if (mapdata->ea)
		free(mapdata->ea);
	if (mapdata->we)
		free(mapdata->we);
	ft_free_split(mapdata->map);
	free(mapdata);
}

//	cleans memory and exits
void	ft_exit(int exit_value, t_vars *vars)
{
	if (vars && vars->mapdata)
		ft_free_map(vars->mapdata);
	if (vars->fd_map > 0 && close(vars->fd_map < 0))
		ft_perror("no idea how we got here but hey, looks like we are clearing up before an emergency exit and the fd of the map doesnt exist", -1);
	if (vars->player)
		free(vars->player);
	if (vars->mlx)
		ft_free_mlx(vars);
	if (vars)
		free(vars);
	exit(exit_value);
}
