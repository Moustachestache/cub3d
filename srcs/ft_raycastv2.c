/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycastv2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:05:56 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/17 20:35:40 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
static float	ft_raylen(float *xraylen, float *yraylen, float raydir, t_vars *vars)
{
	int		xpos;
	int		ypos;
	float	xstep;
	float	ystep;
	int		i;

	xpos = vars->player->xpos / CELL_SIZE;
	ypos = vars->player->ypos / CELL_SIZE;
	i = 0;
	if (angle >= 90 && angle <= 170)
		xstep = -cos(angle) * CELL_SIZE;
	else
		xstep = cos(angle) * CELL_SIZE;
	if (angle >= 180 && angle <= 360)
		ystep = -sin(angle) * CELL_SIZE;
	else
		ystep = sin(angle) * CELL_SIZE;
	while ((ypos >= 0 && ypos <= vars->map->width) && (xpos >= 0 && xpos <= vars->map->height))
	{
		yraylen = ystep * i;
	}
	return (raylen);
}

void	ft_raycastv2(t_vars *vars)
{
	int		i;
	float	xraylen;
	float	yraylen;
	int		raydir;

	i = -1;
	raydir = vars->player->angle - (FOV / 2);
	while (++i < FOV)
	{
		raylen = ft_raylen(&xraylen, &yraylen, raydir, vars);
		ft_drawslice(i, raylen, NULL, vars);
	}
}*/
