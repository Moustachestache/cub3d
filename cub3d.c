/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:49:23 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/29 12:19:29 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_click_exit(void *param)
{
	ft_exit(EXIT_SUCCESS, param);
	return (EXIT_SUCCESS);
}

//	mlx related memory leaks
//	https://github.com/42Paris/minilibx-linux/issues/48
int	main(int ac, char *av[])
{
	t_vars	*vars;

	vars = ft_init_vars(ac, av);
	vars->mapdata = ft_parse_map(vars);
	ft_validate_mapinfo(vars->mapdata, vars);
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, W_WIDTH, W_HEIGHT, "cub3d");
	vars->buffer = ft_calloc(1, sizeof(t_image));
	ft_init_textures(vars->mapdata, vars);
	if (ft_map_validation(vars) > 0)
		ft_exit(ft_perror("Map Is Invalid", EXIT_FAILURE), vars);
	mlx_set_font(vars->mlx, vars->mlx_win, \
		"-misc-fixed-bold-r-normal--18-120-100-100-*-90-iso8859-1");
	mlx_loop_hook(vars->mlx, ft_render, vars);
	mlx_hook(vars->mlx_win, 17, 0L, ft_click_exit, vars);
	mlx_hook(vars->mlx_win, 2, 1L << 0, ft_keyhook, vars);
	mlx_hook(vars->mlx_win, 6, 1L << 6, ft_mouse, vars);
	mlx_mouse_hide(vars->mlx, vars->mlx_win);
	mlx_loop(vars->mlx);
	ft_exit(1, vars);
}
