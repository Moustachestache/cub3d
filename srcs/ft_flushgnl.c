/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flushgnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <mjochum@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:34:58 by mjochum           #+#    #+#             */
/*   Updated: 2024/03/05 16:35:58 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_flushgnl(char *buffer, t_vars *vars)
{
	while (buffer)
	{
		free(buffer);
		buffer = get_next_line(vars->fd_map);
	}
}
