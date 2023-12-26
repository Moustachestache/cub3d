/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:04:26 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/26 16:45:43 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*	strict order & definition: 
no ./path
so ./path
we ./path
ea ./path
f rgb
c rgb

map **char
*/
// NOTE:
// If any misconfiguration of any kind is encountered in the file, the program
// must exit properly and return "Error\n" followed by an explicit error message
// of your choice.

void	ft_fetch_mapdata(t_map *mapdata, t_vars *vars)
{

}

t_map	*ft_parse_map(t_vars *vars)
{
	t_map	*mapdata;

	mapdata = ft_calloc(1, sizeof(t_map));
	ft_fetch_mapdata(mapdata, vars);
	return (mapdata);
}
