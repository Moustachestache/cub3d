/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:42:12 by mjochum           #+#    #+#             */
/*   Updated: 2024/01/27 18:45:10 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static float		ft_transform_x(float x, float increase, float vector)
{
	float		dx;

	vector = ft_deg_to_rad(vector);
	dx = x + cosf(vector) * increase;
	return (dx);
}

static float		ft_transform_y(float y, float increase, float vector)
{
	float		dy;

	vector = ft_deg_to_rad(vector);
	dy = y + -sinf(vector) * increase;
	return (dy);
}

void		ft_transform_player(float *x, float *y, float increase, float vector)
{
	*x = ft_transform_x(*x, increase, vector);
	*y = ft_transform_y(*y, increase, vector);
}

t_pixel		ft_transform_pixel(t_pixel pixel, float increase, float vector)
{
	t_pixel		temp;

	temp.x = ft_transform_x(pixel.x, increase, vector);
	temp.y = ft_transform_y(pixel.y, increase, vector);
	temp.colour = pixel.colour;
	return(temp);
}
