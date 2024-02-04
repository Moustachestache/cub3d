/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:53:27 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/04 16:14:17 by mjochum          ###   ########.fr       */
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

/*
void	put_img_to_img(t_img dst, t_img src, int x, int y) {
	int i;
	int j;

	i = 0;
	while(i < src.w) {
		j = 0;
		while (j < src.h) {
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}
*/
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
