/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawslice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:27:57 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/04 10:59:28 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//	int x			= which slice it is on the x axis
//	float distance	= calculated distance
//	float intersect	= where we hit the texture

void	ft_drawslice(int x, float distance, float intersect, t_image *texture, t_vars *vars)
{
	t_pixel			pixel;
	float			height;
	int				i;

	(void) intersect;
	(void) texture;
	i = 0;
	height = (T_SIZE * W_HEIGHT) / distance;
	pixel = (t_pixel){x, (W_HEIGHT - height) / 2, 0xff00ff};
	while (i < height)
	{
//		pixel.colour = ft_fetch_imgcolour(texture, x, i * intersect);
		ft_img_pix_put(pixel, vars->buffer);
		pixel.y++;
		i++;
	}
}
