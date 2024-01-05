/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:49:23 by mjochum           #+#    #+#             */
/*   Updated: 2024/01/05 20:09:12 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_click_exit(void *param)
{
	ft_exit(EXIT_SUCCESS, param);
	return (EXIT_SUCCESS);
}

//	init vars
//	parse map
//	starts loop
int		main(int ac, char *av[])
{
	t_vars	*vars;

	vars = ft_init_vars(ac, av);
	vars->mapdata = ft_parse_map(vars);
	ft_validate_mapinfo(vars->mapdata, vars);
	//	mlx
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, W_WIDTH, W_HEIGHT, "cub3d");
	//		note: buffer is the image render. We put pixels to it, then refresh the window
	vars->buffer = ft_calloc(1, sizeof(t_image));
	mlx_key_hook(vars->mlx_win, ft_keyhook, vars);
	mlx_hook(vars->mlx_win, 17, 0L, ft_click_exit, vars);
	mlx_loop(vars->mlx);
	//	ok bye
	ft_exit(1, vars);
}
