/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:53:27 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/29 15:26:03 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//	https://pulgamecanica.herokuapp.com/posts/mlx-transparency
//	madlad done did it

unsigned int	ft_fetch_imgcolour(t_image *image, int x, int y)
{
	return (*(unsigned int *)((image->addr + \
	(y * image->len) + (x * image->bpp / 8))));
}

void	ft_put_img(t_pixel pos, t_image *image, t_image *buffer)
{
	int i;
	int j;

	i = 0;
	while (i < image->width)
	{
		j = 0;
		while (j < image->height)
		{
			ft_img_pix_put((t_pixel){pos.x + i, pos.y + j, ft_fetch_imgcolour(image, i, j)}, buffer);
			j++;
		}
		i++;
	}
}


void	ft_put_img_alpha(t_pixel pos, t_image *image, t_image *buffer)
{
	int	x;
	int	y;

	y = image->height;
	while (y >= 0)
	{
		x = image->width;
		while (x >= 0)
		{
			printf("x: %i, y: %i, x+: %i, y+: %i\n",pos.x, pos.y, pos.x + x, pos.y + y);
			if (pos.x + x > 0 && pos.y + y > 0)
				ft_img_pix_put_alpha((t_pixel){pos.x + x, pos.y + y, \
					ft_fetch_imgcolour(image, x, y)}, buffer);
			x--;
		}
		y--;
	}
}
