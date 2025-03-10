/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:37:40 by mjochum           #+#    #+#             */
/*   Updated: 2024/03/01 12:31:25 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_validate(int ac, char *av[], t_vars *vars)
{
	static int	i = 0;
	static int	fd = 0;

	if (ac != 2)
		ft_exit(ft_perror("Unexpected Argument Count", EXIT_FAILURE), vars);
	while (av[1][i])
	{
		if (ft_isposixfile(av[1][i]) == 0)
			ft_exit(ft_perror("Invalid Characters In File Path", \
				EXIT_FAILURE), vars);
		i++;
	}
	if ((av[1][i - 4] != '.') || (av[1][i - 3] != 'c')
		|| (av[1][i - 2] != 'u') || (av[1][i - 1] != 'b'))
		ft_exit(ft_perror("Invalid Filename Extension", EXIT_FAILURE), vars);
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		ft_exit(ft_perror("error", EXIT_FAILURE), vars);
	return (fd);
}

t_vars	*ft_init_vars(int ac, char *av[])
{
	t_vars	*vars;

	if (ac != 2)
		exit(ft_perror("Incorrect Number Of Arguments", EXIT_FAILURE));
	vars = ft_calloc(1, sizeof(t_vars));
	vars->player = ft_calloc(1, sizeof(t_player));
	vars->camera = ft_calloc(1, sizeof(t_camera));
	vars->camera->depth = ft_calloc(W_WIDTH, sizeof(float));
	vars->fd_map = ft_validate(ac, av, vars);
	time(&vars->time);
	time(&vars->oldtime);
	vars->fps[0] = 30;
	return (vars);
}
