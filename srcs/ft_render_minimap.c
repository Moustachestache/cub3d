/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:39:41 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/25 13:52:23 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_map_square(t_pixel start, t_pixel dest, \
	t_image *buffer, t_vars *vars)
{
	if (start.colour == A_COLOR)
		return ;
	while (start.y <= dest.y)
	{
		ft_drawline(start, (t_pixel){dest.x, start.y, 0}, buffer, vars);
		start.y++;
	}
//	ft_drawline((t_pixel){dest.x - 1, start.y - 1 - CELL_SIZE, \
//		start.colour & 0xc8c8c8}, dest, buffer, vars);
//	ft_drawline((t_pixel){start.x, dest.y - 1, \
//		start.colour & 0xc8c8c8}, dest, buffer, vars);
}

static int	ft_get_mapcolour(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (0xffffff);
	if (c == '1')
		return (0x000000);
	if (c == ' ')
		return (0x00ff00);
	else
		return (0xff0000);
}

void	ft_render_minimap(t_image *minimap, t_vars *vars)
{
	static int	x;
	static int	y;

	minimap->width = CELL_SIZE * vars->mapdata->width - CELL_SIZE;
	minimap->height = CELL_SIZE * vars->mapdata->height + CELL_SIZE;
	minimap->image = mlx_new_image(vars->mlx, minimap->width, minimap->height);
	if (minimap->image == NULL)
		ft_exit(ft_perror("Error Initialising Minimap Image", \
			EXIT_FAILURE), vars);
	minimap->addr = mlx_get_data_addr(minimap->image, &minimap->bpp, \
			&minimap->len, &minimap->endian);
	while (vars->mapdata->map[y])
	{
		while (vars->mapdata->map[y][x])
		{
			ft_map_square((t_pixel){x * CELL_SIZE, y * CELL_SIZE, \
				ft_get_mapcolour(vars->mapdata->map[y][x])}, \
			(t_pixel){(x * CELL_SIZE) + CELL_SIZE, \
				(y * CELL_SIZE) + CELL_SIZE, 0}, minimap, vars);
			x++;
		}
		x = 0;
		y++;
	}
}
