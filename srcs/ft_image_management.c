/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:34:54 by mjochum           #+#    #+#             */
/*   Updated: 2024/01/05 18:55:32 by mjochum          ###   ########.fr       */
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

void	ft_img_flush(t_vars *vars)
{
	if (vars->buffer->addr)
			mlx_destroy_image(vars->mlx, vars->buffer->image);
	vars->buffer->image = mlx_new_image(vars->mlx, W_WIDTH, W_HEIGHT);
	vars->buffer->addr = mlx_get_data_addr(vars->buffer->image,\
		&vars->buffer->bpp, &vars->buffer->len, &vars->buffer->endian);
}

//	https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx#creating-an-image
//	draws pixel x/y at correct point in image
void	ft_img_pix_put(t_pixel pixel, t_image *image)
{
    char    *ptr;

	if (pixel.y < 0 || pixel.x < 0 || pixel.x > W_WIDTH || pixel.y > W_HEIGHT)
		return ;
    ptr = image->addr + (pixel.y * image->len + pixel.x * (image->bpp / 8));
    *(unsigned int *)ptr = pixel.colour;
}

//	refreshes and displays all, including image
int	ft_render(t_vars *vars)
{
	// flush
	ft_img_flush(vars);
	//background
	ft_render_background(vars->buffer, vars);
	//interface: mapname,

	//minimap

	//display
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->buffer->image, 0, 0);
	return (0);
}
