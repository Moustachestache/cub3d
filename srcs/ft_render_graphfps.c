/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_graphfps.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <mjochum@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:27:24 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/29 20:40:45 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
			ft_img_pix_put_alpha((t_pixel){x, y, A_COLOR}, image);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_update_graphfps(t_vars *vars)
{
	t_image	*graph;
	int		i;
	int		fps;

	i = 0;
	graph = &vars->graphfps;
	fps = graph->height - vars->fps[1];
	//	move
	ft_put_img_offset(-1, (t_pixel){0, 0, 0x0}, graph, graph);
	while (i < fps)
	{
		ft_img_pix_put_alpha((t_pixel){graph->width - 1, i, A_COLOR}, graph);
		i++;
	}
	ft_drawline((t_pixel){graph->width - 1, fps, 0xffffff},\
		(t_pixel){graph->width - 1, graph->height, 0x0}, graph, vars);
	ft_img_pix_put((t_pixel){graph->width - 1, fps, 0xff0000}, graph);
}

void	ft_render_graphfps(t_vars *vars)
{
	t_image		*ptr;

	ptr = &vars->graphfps;
	ptr->width = 300;
	ptr->height = 120;
	ptr->image = mlx_new_image(vars->mlx, ptr->width, ptr->height);
	ptr->addr = mlx_get_data_addr(ptr->image, &ptr->bpp, \
		&ptr->len, &ptr->endian);
	ft_fill_graph(ptr);
}
