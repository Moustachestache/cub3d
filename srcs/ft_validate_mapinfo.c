/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_mapinfo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:00:03 by mjochum           #+#    #+#             */
/*   Updated: 2024/01/07 11:29:04 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_ismapchar(char c)
{
	if (c == '0' || c == '1' || c =='D' || c == '\n' || c == ' ')
		return (1);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (2);
	return (0);
}

static int	ft_get_playervector(char c)
{
	if (c == 'N')
		return (0);
	if (c == 'E')
		return (90);
	if (c == 'S')
		return (180);
	if (c == 'W')
		return (270);
	return (0);
}

static int	ft_validate_characters(t_map *mapdata, t_vars *vars)
{
	int			i;
	int			j;
	int			temp;

	i = 0;
	j = 0;
	while (mapdata->map[i])
	{
		while (mapdata->map[i][j])
		{
			temp = ft_ismapchar(mapdata->map[i][j]);
			if (temp == 2 && vars->player->start == 0)
			{
				vars->player->start = mapdata->map[i][j];
				vars->player->vector = ft_get_playervector(mapdata->map[i][j]);
				vars->player->xpos = (j * CELL_SIZE) + (CELL_SIZE / 2);
				vars->player->ypos = (i * CELL_SIZE) + (CELL_SIZE / 2);
			}
			else if (temp != 1)
				ft_exit(ft_perror("Map Has Too Many Starting Points", EXIT_FAILURE), vars);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
//	rules
//	- 1 everywhere around
//	- start point is either N,S,E or W. No double no more.
//	- validates use of approved characters. [0,1,N,S,E,W,D]
int	ft_validate_mapinfo(t_map *mapdata, t_vars *vars)
{
	if (!ft_validate_characters(mapdata, vars))
		ft_exit(ft_perror("Map Has Invalid Characters", EXIT_FAILURE), vars);
	//	start from player
	return (1);
}
