/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:30:38 by mjochum           #+#    #+#             */
/*   Updated: 2024/01/07 12:19:39 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_keyhook(int keycode, t_vars *vars)
{
//debug
printf("[%p] keycode: %i\n", vars, keycode);
	if (keycode == 65307)
		ft_exit(EXIT_SUCCESS, vars);
	else if (keycode == 119)
		vars->player->ypos--;
	else if (keycode == 115)
		vars->player->ypos++;
	else if (keycode == 97)
		vars->player->xpos--;
	else if (keycode == 100)
		vars->player->xpos++;

	ft_render(vars);
	return (0);
}
