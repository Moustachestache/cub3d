/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:34:54 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/29 15:29:05 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_interface_text(t_vars *vars)
{
	char	*fps;

	fps = NULL;
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
	fps = ft_itoa(vars->fps[1]);
	ft_write_toscreen((t_pixel){W_WIDTH - 60, 18, 0x0}, fps, vars);
	ft_write_toscreen((t_pixel){W_WIDTH - 40, 18, 0x0}, "fps ", vars);
	free(fps);
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
		ft_put_img((t_pixel){W_WIDTH - 200, 120, 0x0}, &vars->graphfps, vars->buffer);
	}
}

//	refreshes and displays all, including image
int	ft_render(t_vars *vars)
{
	ft_frame(vars);
	ft_img_flush(vars);
	ft_put_img((t_pixel){0, 0, 0}, &vars->background, vars->buffer);
	ft_draw_rays(vars);
	ft_render_interface(vars->buffer, vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, \
		vars->buffer->image, 0, 0);
	ft_interface_text(vars);
	return (0);
}
