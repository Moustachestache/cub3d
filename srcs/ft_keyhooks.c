/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:30:38 by mjochum           #+#    #+#             */
/*   Updated: 2024/01/04 10:10:48 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_keyhook(int keycode, t_vars *vars)
{
//debug
printf("[%p] keycode: %i\n", vars, keycode);
	if (keycode == 65307)
		ft_exit(EXIT_SUCCESS, vars);
	ft_render(vars);
	return (0);
}
