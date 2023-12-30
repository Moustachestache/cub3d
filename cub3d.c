/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:49:23 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/30 14:28:17 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//	init vars
//	parse map
//	starts loop
int		main(int ac, char *av[])
{
	t_vars	*vars;

	vars = ft_init_vars(ac, av);
	vars->mapdata = ft_parse_map(vars);

	//	debug
	printf("map info:\n[no: %s] [so: %s] [we: %s] [ea: %s] [c: %i] [f: %i]\n", vars->mapdata->no, vars->mapdata->so, vars->mapdata->we, vars->mapdata->ea, vars->mapdata->ceiling, vars->mapdata->floor);
	printf("all ok i guess\n");
}
