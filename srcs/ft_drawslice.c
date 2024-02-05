/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawslice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:27:57 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/05 14:29:35 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//	int x			= which slice it is on the x axis
//	float distance	= calculated distance
//	float intersect	= where we hit the texture

void	ft_drawslice(int x, t_camera *camera, t_image *texture, t_vars *vars)
{
	t_pixel			pixel;
	float			height;
	int				i;

	(void) texture;
	i = 0;
	height = (T_SIZE * W_HEIGHT) / camera->wall_dist;
	pixel = (t_pixel){x, (W_HEIGHT - height) / 2, 0xff00ff};
	while (i < height)
	{
//		pixel.colour = ft_fetch_imgcolour(texture, x, i * intersect);
		ft_img_pix_put(pixel, vars->buffer);
		pixel.y++;
		i++;
	}
}
