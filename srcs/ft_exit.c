/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:31:50 by mjochum           #+#    #+#             */
/*   Updated: 2024/03/01 12:37:38 by mjochum          ###   ########.fr       */
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

static void	ft_free_imagearray(int size, t_image *target, t_vars *vars)
{
	while (size >= 0)
	{
		if (target[size].image)
			mlx_destroy_image(vars->mlx, target[size].image);
		size--;
	}
}

static void	ft_free_map(t_map *mapdata, t_vars *vars)
{
	(void) vars;
	if (mapdata->no)
		free(mapdata->no);
	if (mapdata->so)
		free(mapdata->so);
	if (mapdata->ea)
		free(mapdata->ea);
	if (mapdata->we)
		free(mapdata->we);
	if (mapdata->door)
		free(mapdata->door);
	ft_free_imagearray(4, mapdata->texture, vars);
	if (mapdata->sprite)
	{
		ft_free_imagearray(3, mapdata->stexture, vars);
		free(mapdata->stexture);
		free(mapdata->sprite);
	}
	ft_free_split(mapdata->map);
	free(mapdata->texture);
	free(mapdata);
}

//	mlx_destroy_image(vars->mlx, image->image);
static void	ft_destroy_images(t_vars *vars)
{
	if (vars->background.image)
		mlx_destroy_image(vars->mlx, vars->background.image);
	if (vars->minimap.image)
		mlx_destroy_image(vars->mlx, vars->minimap.image);
	if (vars->buffer && vars->buffer->image)
		mlx_destroy_image(vars->mlx, vars->buffer->image);
	if (vars->graphfps.image)
		mlx_destroy_image(vars->mlx, vars->graphfps.image);
	if (vars->buffer)
		free(vars->buffer);
	if (vars->logo.image)
		mlx_destroy_image(vars->mlx, vars->logo.image);
	if (vars->tdefault.image)
		mlx_destroy_image(vars->mlx, vars->tdefault.image);
}

//	cleans memory and exits
void	ft_exit(int exit_value, t_vars *vars)
{
	if (vars->fd_map > 0 && close(vars->fd_map < 0))
		ft_perror("huh, that\'s weird", -1);
	if (vars->mapdata)
		ft_free_map(vars->mapdata, vars);
	if (vars)
		ft_destroy_images(vars);
	if (vars->player)
		free(vars->player);
	if (vars->camera->depth)
		free(vars->camera->depth);
	if (vars->camera)
		free(vars->camera);
	if (vars->mlx)
		ft_free_mlx(vars);
	if (vars)
		free(vars);
	exit(exit_value);
}
