/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:39:41 by mjochum           #+#    #+#             */
/*   Updated: 2024/01/16 13:47:52 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_map_square(t_pixel start, t_pixel dest, t_vars *vars)
{
	if (start.colour == 0x00ff00)
		return ;
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
		return (0x00ff00);
	else
		return (0x000000);
}

static void	ft_drawplayer(t_player *player, t_vars *vars)
{
	t_pixel		a;
	t_pixel		b;
	int		colour;

	colour = 0xff0000;
	a = (t_pixel){player->xpos - 2, player->ypos - 2, colour};
	b = (t_pixel){player->xpos + 2, player->ypos + 2, 0};
	ft_map_square(a, b, vars);
	a = (t_pixel){player->xpos, player->ypos, colour};
	ft_drawline(a, ft_transform_pixel(a, 30, vars->player->angle), vars);
}

void	ft_render_minimap(t_image *image, t_vars *vars)
{
	int	x;
	int	y;

	(void) image;
	x = 0;
	y = 0;
	while (vars->mapdata->map[y])
	{
		while (vars->mapdata->map[y][x])
		{
			ft_map_square((t_pixel){x * CELL_SIZE, y * CELL_SIZE, ft_get_mapcolour(vars->mapdata->map[y][x])},\
			(t_pixel){(x * CELL_SIZE) + CELL_SIZE, (y * CELL_SIZE) + CELL_SIZE, 0},\
			vars);
			x++;
		}
		x = 0;
		y++;
	}
	ft_drawplayer(vars->player, vars);
}
