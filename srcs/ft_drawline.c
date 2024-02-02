/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 07:23:09 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/02 15:23:38 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_octan_0(t_pixel start, t_pixel dest, t_vars *vars)
{
	float	slope;
	float	error;

	error = 0;
	slope = (float)(dest.x - start.x) / (float)(dest.y - start.y);
	while (start.y >= dest.y)
	{
		ft_img_pix_put(start, vars->buffer);
		error += slope;
		if (error < 0)
		{
			start.x++;
			error = 1;
		}
		start.y--;
	}
}

static void	ft_octan_1(t_pixel start, t_pixel dest, t_vars *vars)
{
	float	slope;
	float	error;

	error = 0;
	slope = (float)(dest.y - start.y) / (float)(dest.x - start.x);
	while (start.x <= dest.x)
	{
		ft_img_pix_put(start, vars->buffer);
		error += slope;
		if (error < 0)
		{
			start.y--;
			error = 1;
		}
		start.x++;
	}
}

static void	ft_octan_2(t_pixel start, t_pixel dest, t_vars *vars)
{
	float	slope;
	float	error;

	error = 0;
	slope = (float)(dest.y - start.y) / (float)(dest.x - start.x);
	while (start.x <= dest.x)
	{
		ft_img_pix_put(start, vars->buffer);
		error += slope;
		if (error > 1)
		{
			start.y++;
			error = 0;
		}
		start.x++;
	}
}

static void	ft_octan_3(t_pixel start, t_pixel dest, t_vars *vars)
{
	float	slope;
	float	error;

	error = 0;
	slope = (float)(dest.x - start.x) / (float)(dest.y - start.y);
	while (start.y <= dest.y)
	{
		ft_img_pix_put(start, vars->buffer);
		error += slope;
		if (error > 1)
		{
			start.x++;
			error = 0;
		}
		start.y++;
	}
}

void	ft_drawline(t_pixel start, t_pixel dest, t_vars *vars)
{
	t_pixel		swap;
	int			colour;
	int			x;
	int			y;

	swap = (t_pixel){0, 0, 0};
	if (start.x > dest.x)
	{
		colour = start.colour;
		swap = start;
		start = dest;
		dest = swap;
		start.colour = colour;
	}
	x = dest.x - start.x;
	y = dest.y - start.y;
	if (y <= 0 && x + y <= 0)
		ft_octan_0(start, dest, vars);
	else if (y <= 0 && x + y >= 0)
		ft_octan_1(start, dest, vars);
	else if (y >= 0 && x - y >= 0)
		ft_octan_2(start, dest, vars);
	else if (y >= 0 && x - y <= 0)
		ft_octan_3(start, dest, vars);
}
