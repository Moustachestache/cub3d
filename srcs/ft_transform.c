/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:42:12 by mjochum           #+#    #+#             */
/*   Updated: 2024/01/08 22:19:13 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int		ft_transform_x(int x, int increase, float vector)
{
	int		dx;

	vector = ft_deg_to_rad(vector);
	dx = x + -cosf(vector) * increase;
	return (dx);
}

static int		ft_transform_y(int y, int increase, float vector)
{
	int		dy;

	vector = ft_deg_to_rad(vector);
	dy = y + sinf(vector) * increase;
	return (dy);
}

void		ft_transform_player(int	*x, int *y, int increase, float vector)
{
	*x = ft_transform_x(*x, increase, vector);
	*y = ft_transform_y(*y, increase, vector);
}

t_pixel		ft_transform_pixel(t_pixel pixel, int increase, float vector)
{
	t_pixel		temp;

	temp.x = ft_transform_x(pixel.x, increase, vector);
	temp.y = ft_transform_y(pixel.y, increase, vector);
	temp.colour = pixel.colour;
	return(temp);
}
