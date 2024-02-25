/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:34:54 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/25 14:51:11 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_interface_text(t_vars *vars)
{
	if (vars->interface_toggle != 0)
	{
		ft_write_toscreen(\
			(t_pixel){10, 5 + CELL_SIZE * (vars->mapdata->height + 4), 0x0}, \
			"move: [w] [s].turn: [mouse] & [a] [d].interact: [space]", \
			vars);
	}
	else
	{
		ft_write_toscreen(\
			(t_pixel){10, 20, 0x0}, "interface: [i]", vars);
	}
}

static void	ft_render_interface(t_image *image, t_vars *vars)
{
	(void) image;
	if (vars->interface_toggle != 0)
	{
		ft_put_img((t_pixel){0, 0, 0x0}, &vars->minimap, vars->buffer);
		ft_drawplayer(vars->player, vars);
		ft_put_img((t_pixel){vars->minimap.width + 5, -20, 0x0}, \
			&vars->logo, vars->buffer);
	}
}

//	refreshes and displays all, including image
int	ft_render(t_vars *vars)
{
	ft_img_flush(vars);
	ft_put_img((t_pixel){0, 0, 0}, &vars->background, vars->buffer);
	ft_draw_rays(vars);
	ft_render_interface(vars->buffer, vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
		vars->buffer->image, 0, 0);
	ft_interface_text(vars);
	return (0);
}
