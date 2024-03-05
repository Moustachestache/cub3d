/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:42:12 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/02 15:22:59 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static float	ft_transform_x(float x, float increase, float angle)
{
	float		dx;

	angle = ft_deg_to_rad(angle);
	dx = x + cosf(angle) * increase;
	return (dx);
}

static float	ft_transform_y(float y, float increase, float angle)
{
	float		dy;

	angle = ft_deg_to_rad(angle);
	dy = y + -sinf(angle) * increase;
	return (dy);
}

static void	ft_step(float *x, float *y, \
		float new_x, float new_y)
{
	*x = new_x;
	*y = new_y;
}

void	ft_check_square(float *x, float *y, \
	float increase, float angle, t_map *mapdata, int key)
{
	float	temp_x;
	float	temp_y;
	if (key == 32)
	{
		temp_x = ft_transform_x(*x, increase * 4, angle);
		temp_y = ft_transform_y(*y, increase * 4, angle);
		if (mapdata->map[(int)temp_y][(int)temp_x] == 'd')
				mapdata->map[(int)temp_y][(int)temp_x] = 'D';
		else if (mapdata->map[(int)temp_y][(int)temp_x] == 'D')
				mapdata->map[(int)temp_y][(int)temp_x] = 'd';
	}
	else if (key == 119 || key == 65362 || key == 122 || key == 115 \
		|| key == 65364 || key == 100 || key == 97 || key == 113)
	{
		temp_x = ft_transform_x(*x, increase, angle);
		temp_y = ft_transform_y(*y, increase, angle);
		if (mapdata->map[(int)temp_y][(int)temp_x] == '0' \
			|| mapdata->map[(int)temp_y][(int)temp_x] == 'd')
			ft_step(x, y, temp_x, temp_y);
	}
}

t_pixel	ft_transform_pixel(t_pixel pixel, float increase, float vector)
{
	t_pixel		temp;

	temp.x = ft_transform_x(pixel.x, increase, vector);
	temp.y = ft_transform_y(pixel.y, increase, vector);
	temp.colour = pixel.colour;
	return (temp);
}
