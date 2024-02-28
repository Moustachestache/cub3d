/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <mjochum@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:24:49 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/27 18:14:16 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_getframe(t_vars *vars)
{
	return (vars->frame);
}

int	ft_frame(t_vars *vars)
{
	time(&vars->time);
	if (vars->time - vars->oldtime >= 1)
	{
		if (vars->frame < 3)
			vars->frame++;
		else
			vars->frame = 0;
		vars->oldtime = vars->time;
	}
	return (1);
}
