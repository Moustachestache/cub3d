/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deg_to_rad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:45:30 by mjochum           #+#    #+#             */
/*   Updated: 2024/01/16 13:48:13 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//	merci gregou
//	https://github.com/Omjihn
float	ft_deg_to_rad(float a)
{
	return (a * M_PI / 180.0);
}
/*
float   ft_turn_x(float angle, t_camera *camera)
{
	return (camera->dir[0] * cos(angle) - camera->dir[1] * sin(angle);
}

float	ft_turn_y(float angle, t_camera *camera)
{
	return (camera->dir[0] * sin(angle) + camera->dir[1] * cos(angle);
}*/
