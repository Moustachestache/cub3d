/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:34:54 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/01 14:46:48 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_render_background(t_image *image, t_vars *vars)
{
	int	half;
	int	y;
	int	x;

	y = 0;
	x = 0;
	half = W_HEIGHT / 2;
	while (y <= half)
	{
		while (x < W_WIDTH)
		{
			ft_img_pix_put((t_pixel){x, y, vars->mapdata->ceiling}, image);
			x++;
		}
		x = 0;
		y++;
	}
	while (y <= W_HEIGHT)
	{
		while (x < W_WIDTH)
		{
			ft_img_pix_put((t_pixel){x, y, vars->mapdata->floor}, image);
			x++;
		}
		x = 0;
		y++;
	}
}

static void	ft_render_interface(t_image *image, t_vars *vars)
{
	//	write mapname, keys, framerate?
	int		offset;

	(void) image;
	offset = CELL_SIZE * (vars->mapdata->height + 4);
	if (vars->interface_toggle == 0)
		ft_write_toscreen(10, 20, "toggle interface: [i]", 0x0, vars);
	else
	{
		ft_write_toscreen(10, offset,\
			"toggle interface: [i]\nturn: [mouse] + [a] & [d]\nmove: [w] & [s]\ninteract: [space]",\
			0x0, vars);
	}
}

//	refreshes and displays all, including image
int	ft_render(t_vars *vars)
{
	// 	flush
	ft_img_flush(vars);
	//	background
	ft_render_background(vars->buffer, vars);
	//	calculate  raycasting.
	//ft_raycast(vars);
	//	minimap
	if (vars->interface_toggle != 0)
		ft_render_minimap(vars->buffer, vars);
	//	display
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->buffer->image, 0, 0);
	//	do writing now so it isnt flushed by put_image_to_window
	ft_render_interface(vars->buffer, vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->mapdata->texture[0].image, 100, 100);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->mapdata->texture[1].image, 250, 100);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->mapdata->texture[2].image, 100, 250);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->mapdata->texture[3].image, 250, 250);
	//mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->mapdata->texture[4].image, 100, 100);
	//mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->mapdata->texture[5].image, 100, 100);
	return (0);
}
