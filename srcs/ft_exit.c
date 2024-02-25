/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:31:50 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/25 09:42:14 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_destroy_image(t_image *image, t_vars *vars)
{
	if (image != NULL && image->image)
		mlx_destroy_image(vars->mlx, image->image);
}

static void	ft_free_mlx(t_vars *vars)
{
	if (vars->mlx_win)
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

static void	ft_free_map(t_map *mapdata, t_vars *vars)
{
	static int	i = -1;

	if (mapdata->no)
		free(mapdata->no);
	if (mapdata->so)
		free(mapdata->so);
	if (mapdata->ea)
		free(mapdata->ea);
	if (mapdata->we)
		free(mapdata->door);
	if (mapdata->we)
		free(mapdata->sprite);
	if (mapdata->we)
		free(mapdata->we);
	ft_free_split(mapdata->map);
	while (++i < 6)
		ft_destroy_image(&mapdata->texture[i], vars);
	free(mapdata->texture);
	free(mapdata);
}

//	cleans memory and exits
void	ft_exit(int exit_value, t_vars *vars)
{
	if (vars && vars->mapdata)
		ft_free_map(vars->mapdata, vars);
	if (vars->fd_map > 0 && close(vars->fd_map < 0))
		ft_perror("huh, that\'s weird", -1);
	if (vars->player)
		free(vars->player);
	if (vars->background.image)
		mlx_destroy_image(vars->mlx, vars->background.image);
	if (vars->minimap.image)
		mlx_destroy_image(vars->mlx, vars->minimap.image);
	if (vars->buffer && vars->buffer->image)
		mlx_destroy_image(vars->mlx, vars->buffer->image);
	if (vars->logo.image)
		ft_destroy_image(&vars->logo, vars);
	if (vars->buffer)
		free(vars->buffer);
	if (vars->camera)
		free(vars->camera);
	if (vars->mlx)
		ft_free_mlx(vars);
	if (vars)
		free(vars);
	exit(exit_value);
}
