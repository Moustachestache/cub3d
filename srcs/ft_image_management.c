/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:34:54 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/02 14:33:24 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_render_background(t_image *image, t_vars *vars)
{
	int	half;
	int	y;
	int	x;

	y = -1;
	x = -1;
	half = W_HEIGHT / 2;
	while (++y <= half)
	{
		while (++x < W_WIDTH)
			ft_img_pix_put((t_pixel){x, y, vars->mapdata->ceiling}, image);
		x = -1;
	}
	while (++y <= W_HEIGHT)
	{
		while (++x < W_WIDTH)
			ft_img_pix_put((t_pixel){x, y, vars->mapdata->floor}, image);
		x = -1;
	}
}

static void	ft_render_interface(t_image *image, t_vars *vars)
{
	(void) image;
	if (vars->interface_toggle == 0)
		ft_write_toscreen(\
			(t_pixel){10, 20, 0x0}, "toggle interface: [i]", vars);
	else
	{
		ft_write_toscreen(\
			(t_pixel){10, CELL_SIZE * (vars->mapdata->height + 4), 0x0}, \
			"toggle interface: [i]\nturn: [mouse] + [a] & [d]\nmove: \
			[w] & [s]\ninteract: [space]", vars);
	}
}

//	refreshes and displays all, including image
int	ft_render(t_vars *vars)
{
	ft_img_flush(vars);
	ft_render_background(vars->buffer, vars);
	if (vars->interface_toggle != 0)
		ft_render_minimap(vars->buffer, vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
		vars->buffer->image, 0, 0);
	ft_render_interface(vars->buffer, vars);
	//	test
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->mapdata->texture[0].image, 100, 100);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->mapdata->texture[1].image, 250, 100);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->mapdata->texture[2].image, 100, 250);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->mapdata->texture[3].image, 250, 250);
	//mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->mapdata->texture[4].image, 100, 100);
	//mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->mapdata->texture[5].image, 100, 100);
	return (0);
}
