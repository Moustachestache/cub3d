/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_flush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:08:44 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/02 15:24:08 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_img_flush(t_vars *vars)
{
	if (vars->buffer->addr)
		mlx_destroy_image(vars->mlx, vars->buffer->image);
	vars->buffer->image = mlx_new_image(vars->mlx, W_WIDTH, W_HEIGHT);
	vars->buffer->addr = mlx_get_data_addr(vars->buffer->image, \
		&vars->buffer->bpp, &vars->buffer->len, &vars->buffer->endian);
}
