/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:39:41 by mjochum           #+#    #+#             */
/*   Updated: 2024/01/07 18:05:25 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_map_square(t_pixel start, t_pixel dest, t_vars *vars)
{
	while (start.y <= dest.y)
	{
		ft_drawline(start, (t_pixel){dest.x, start.y, 0}, vars);
		start.y++;
	}
	ft_drawline((t_pixel){dest.x - 1, start.y - 1 - CELL_SIZE, start.colour & 0xc8c8c8}, dest, vars);
	ft_drawline((t_pixel){start.x, dest.y - 1, start.colour & 0xc8c8c8}, dest, vars);
}

static int	ft_get_mapcolour(char c)
{
	if (c == '0' || c== 'N' || c == 'S' || c == 'W' || c == 'E')
		return (0xffffff);
	if (c == '1')
		return (0x000000);
	if (c == ' ')
		return (0x000000);
	else
		return (0x000000);
}

static void	ft_drawplayer(int y_offset, t_vars *vars)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	x = vars->player->xpos;
	y = vars->player->ypos + y_offset;
	//	rectangle
	while (i <= 4)
	{
		ft_drawline((t_pixel){x - 2, y + i, 0xff0000}, (t_pixel){x + 2, y + i, 0}, vars);
		i++;
	}
	//	pipou
}

void	ft_render_minimap(t_image *image, t_vars *vars)
{
	int		height;
	int		x;
	int		y;
	int		colour;

	(void) image;
	x = 0;
	y = 0;
	height = W_HEIGHT - CELL_SIZE - vars->mapdata->height * CELL_SIZE;
	while (y <= vars->mapdata->height)
	{
		while (vars->mapdata->map[y][x])
		{
			colour = ft_get_mapcolour(vars->mapdata->map[y][x]);
			ft_map_square(\
			(t_pixel){(x * CELL_SIZE), (y * CELL_SIZE) + height, colour},\
			(t_pixel){(x * CELL_SIZE) + CELL_SIZE, (y * CELL_SIZE) + CELL_SIZE + height, 0},\
			vars);
			x++;
		}
		y++;
		x = 0;
	}
	ft_drawplayer(height, vars);
}
