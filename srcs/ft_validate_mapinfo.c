/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_mapinfo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:00:03 by mjochum           #+#    #+#             */
/*   Updated: 2024/01/02 15:11:01 by mjochum          ###   ########.fr       */
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
				vars->player->start = mapdata->map[i][j];
			else if (temp != 1)
				return (0);
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
		ft_exit(ft_perror("Map Has Invalid Characters", 1), vars);
	//	start from player
	return (1);
}
