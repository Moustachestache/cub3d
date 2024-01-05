/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:34:54 by mjochum           #+#    #+#             */
/*   Updated: 2024/01/05 20:09:23 by mjochum          ###   ########.fr       */
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
	int		x;
	int		y;
	int		colour;

	(void) vars;
	x = 0;
	y = W_HEIGHT - (W_HEIGHT / 5);
	colour = 4539717;
	while (y <= W_HEIGHT)
	{
		while (x < W_WIDTH)
		{
			ft_img_pix_put((t_pixel){x, y, colour}, image);
			x++;
		}
		x = 0;
		y++;
	}
}

//	refreshes and displays all, including image
int	ft_render(t_vars *vars)
{
	// flush
	ft_img_flush(vars);
	//background
	ft_render_background(vars->buffer, vars);
	//interface: mapname,
	ft_render_interface(vars->buffer, vars);
	//minimap

	//display
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->buffer->image, 0, 0);
	return (0);
}
