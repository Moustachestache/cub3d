/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_mapinfo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:00:03 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/27 17:02:38 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_ismapchar(char c)
{
	if (c == '0' || c == '1' || c == 'D' || c == 'd' || c == 's' || c == '\n' || c == ' ')
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
				ft_player_init(j, i, mapdata->map[i][j], vars);
			else if (temp != 1)
				ft_exit(ft_perror("Map Has Too Many Starting Points", \
					EXIT_FAILURE), vars);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_validate_mapinfo(t_map *mapdata, t_vars *vars)
{
	if (!ft_validate_characters(mapdata, vars))
		ft_exit(ft_perror("Map Has Invalid Characters", EXIT_FAILURE), vars);
	return (1);
}
