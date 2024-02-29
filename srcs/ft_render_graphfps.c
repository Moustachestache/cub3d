/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_graphfps.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <mjochum@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:27:24 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/29 15:43:59 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_moveimage(t_image *graph)
{
	ft_put_img_alpha((t_pixel){-1, 0, 0x0}, graph, graph);
}

static void	ft_fill_graph(t_image *image)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < image->height)
	{
		while (x < image->width)
		{
			ft_img_pix_put_alpha((t_pixel){x, y, 0x00ff00}, image);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_update_graphfps(t_vars *vars)
{
//		t_pixel pix;

//		pix = (t_pixel){200, 120, 0x00ff00};
		ft_moveimage(&vars->graphfps);
//		while (pix.x >= 0)
//		{
//			ft_img_pix_put_alpha(pix, &vars->graphfps);
//			pix.x -= 1;
//		}
		ft_img_pix_put_alpha((t_pixel){200, vars->fps[1], 0xff0000}, &vars->graphfps);
}

void	ft_render_graphfps(t_vars *vars)
{
	t_image		*ptr;

	ptr = &vars->graphfps;
	ptr->width = 200;
	ptr->height = 120;
	ptr->image = mlx_new_image(vars->mlx, ptr->width, ptr->height);
	ptr->addr = mlx_get_data_addr(ptr->image, &ptr->bpp, &ptr->len, &ptr->endian);
	ft_fill_graph(ptr);
}
