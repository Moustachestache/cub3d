/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawplayer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:41:19 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/04 17:58:44 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_drawplayer(t_player *player, t_vars *vars)
{
	t_pixel		start;
	t_pixel		dest;

	(void) vars;
	start = (t_pixel){player->xpos - 2, player->ypos - 2, 0xff0000};
	dest = (t_pixel){player->xpos + 2, player->ypos + 2, 0xff0000};
	while (start.y <= dest.y)
	{
		ft_drawline(start, (t_pixel){dest.x, start.y, start.colour}, vars->buffer, vars);
		start.y++;
	}
	start = (t_pixel){player->xpos, player->ypos, 0xff0000};
	ft_img_pix_put(ft_transform_pixel((t_pixel){start.x, start.y, 0xff0000}, 4, vars->player->angle), vars->buffer);
	ft_img_pix_put(ft_transform_pixel((t_pixel){start.x, start.y, 0xff0000}, 5, vars->player->angle), vars->buffer);
	ft_img_pix_put(ft_transform_pixel((t_pixel){start.x, start.y, 0xff0000}, 6, vars->player->angle), vars->buffer);
	ft_img_pix_put(ft_transform_pixel((t_pixel){start.x, start.y, 0xff0000}, 7, vars->player->angle), vars->buffer);
}
