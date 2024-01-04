/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 07:23:09 by mjochum           #+#    #+#             */
/*   Updated: 2024/01/04 13:30:53 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//	ft_img_pix_put(t_pixel, t_image))

static void	ft_octan_0(t_pixel start, t_pixel dest, t_vars *vars)
{
//		error, slope, etc
}

void		ft_drawline(t_pixel start, t_pixel dest, t_vars *vars)
{
	// swap
	t_pixel	swap;

	swap = (t_pixel){0, 0, 0};
	if (start.x < dest.x)
	{
		swap = start;
		start = dest;
		dest = swap;
	}
	ft_octan_0(start, dest, vars);
}
