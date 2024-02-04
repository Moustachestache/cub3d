/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_pix_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:06:36 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/02 20:53:03 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_img_pix_put(t_pixel pixel, t_image *image)
{
	char	*ptr;

	if (pixel.colour == A_COLOR)
		return ;
	if (pixel.y < 0 || pixel.x < 0 || pixel.x > W_WIDTH || pixel.y > W_HEIGHT)
		return ;
	ptr = image->addr + (pixel.y * image->len + pixel.x * (image->bpp / 8));
	*(unsigned int *)ptr = pixel.colour;
}
