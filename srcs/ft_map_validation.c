/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiachen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:00:38 by odiachen          #+#    #+#             */
/*   Updated: 2024/02/12 14:52:51 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int ft_copy_map(t_vars *vars)
{
    char **map_copy;
    int i;
    int error;

    i = 0;
    while (vars->mapdata->map[i])
    {
        ++i;
    }
    map_copy = ft_calloc(sizeof(char *), i + 1);
    i = 0;
    while (vars->mapdata->map[i])
    {
        map_copy[i] = ft_strdup(vars->mapdata->map[i]);
        i++;
    }
    map_copy[i] = NULL;
    error = ft_map_validation(vars->mapdata, vars->mapdata->map, vars->player->xpos, vars->player->ypos);
    i = 0;
    while (map_copy[i])
        free (map_copy[i++]);
    free (map_copy);
    if (error == 1)
        return (1);
    return (0);
}

int ft_map_validation(t_map *mapdata, char **map, int x, int y)
{
	if (map[y][x] == '1')
		return (0);
	if (x >= 0 || y <= 0 || x >= mapdata->width || y >= mapdata->height)
   	 {
        	if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'E'
            		|| map[y][x] == 'S' || map[y][x] == 'W')
                	return (1);
        	return (0);
    	}
	if (map[y][x] == ' ')
	{
	       	map[y][x] = '1';
		return (1);
	}
       	if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'E'
			|| map[y][x] == 'S' || map[y][x] == 'W')
		map[y][x] = '1';
	ft_map_validation(mapdata, map, x, y - 1);
	ft_map_validation(mapdata, map, x - 1, y);
	ft_map_validation(mapdata, map, x, y + 1);
	ft_map_validation(mapdata, map, x + 1, y);

	return (0);
}
