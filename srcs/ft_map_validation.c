/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiachen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:00:38 by odiachen          #+#    #+#             */
/*   Updated: 2024/02/25 10:45:26 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	**ft_copy_map(t_map *mapdata)
{
	char	**mapcopy;
	int		i;

	i = -1;
	mapcopy = ft_calloc(mapdata->height + 1, sizeof(char *));
	while (++i <= mapdata->height)
	{
		mapcopy[i] = ft_calloc(mapdata->width, sizeof(char));
		ft_memset(mapcopy[i], ' ', mapdata->width);
		ft_memcpy(mapcopy[i], mapdata->map[i], mapdata->width);
	}
	return (mapcopy);
}

//	wow i should
//	give up on programming
//	and open a vomit factory
static int	ft_hasnull(int x, int y, char **map, t_vars *vars)
{
	if (x + 1 > vars->mapdata->width || y > vars->mapdata->height)
		return (1);
	else if (map[y][x + 1] != '1')
		return (1);
	if (x - 1 > vars->mapdata->width || y > vars->mapdata->height)
		return (1);
	else if (map[y][x - 1] != '1')
		return (1);
	if (x > vars->mapdata->width || y + 1 > vars->mapdata->height)
		return (1);
	else if (map[y + 1][x] != '1')
		return (1);
	if (x > vars->mapdata->width || y - 1 > vars->mapdata->height)
		return (1);
	else if (map[y - 1][x] != '1')
		return (1);
	return (0);
}

static int	ft_validate(int x, int y, char **map, t_vars *vars)
{
	int	retval;

	retval = 0;
	if ((x < 0) || (y < 0) || (x > vars->mapdata->width) \
				|| (y > vars->mapdata->height))
		return (1);
	if (map[y][x] == ' ')
		retval = ft_hasnull(x, y, map, vars);
	if (map[y][x] == '1' || map[y][x] == '2')
		return (0);
	map[y][x] = '2';
	retval += ft_validate(x + 1, y, map, vars);
	retval += ft_validate(x - 1, y, map, vars);
	retval += ft_validate(x, y + 1, map, vars);
	retval += ft_validate(x, y - 1, map, vars);
	return (retval);
}

int	ft_map_validation(t_vars *vars)
{
	char	**map;
	int		retval;
	int		i;

	i = -1;
	map = ft_copy_map(vars->mapdata);
	retval = ft_validate(vars->player->xpos, \
		vars->player->ypos, map, vars);
int	y = -1;
while (++y <= vars->mapdata->height)
{
	printf("[%5i - %s]\n", y, map[y]);
}
	while (++i <= vars->mapdata->height)
		free(map[i]);
	free(map);
	return (retval);
}
