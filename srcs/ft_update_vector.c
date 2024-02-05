/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:52:51 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/05 14:14:43 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_update_angle(int *angle, int add, t_vars *vars)
{
	(void) vars;
/*	*angle = (*angle + add) % 359;
	if (angle < 0)
		*angle = 359 - abs(*angle);*/
	angle = (angle + add) % 359;
	/*if (angle > 359)
		angle = 359 - abs(angle);*/
}
