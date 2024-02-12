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

/*
t_map	*ft_copy_map(t_map *mapdata)
{
	char	**mapcopy;
	int		i;

	mapcopy = ft_calloc(mapdata->height, sizeof(char *));
	while (i < mapdata->height)
	{
		mapcopy[i] = ft_calloc(mapdata->width + 1, sizeof(char));
		// caca
		//	replace with ft memcpy
		memset(mapcopy[i], ' ', mapdata->width);
		ft_memcpy(mapcopy[i], mapdata->map[i], mapdata->width);
		i++;
	}
	return (mapcopy);
}

int		ft_map_validation(t_vars *vars)
{
	char	**map;
	int		retval;

	mapdata = ft_copy_map(vars->mapdata);
	ft_retval = ft_
	//	end
	ft_free_split(map);
	return (retval);
}*/
int	ft_map_validation(t_vars *vars)
{
	(void) vars;
	return 0;
}
