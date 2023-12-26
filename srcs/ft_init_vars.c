/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:37:40 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/26 16:07:22 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//	checks if the str conforms to the POSIX path character norm & file character norm
//	https://www.ibm.com/docs/en/zos/2.1.0?topic=locales-posix-portable-file-name-character-set
static int ft_isposixfile(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c == '_') || (c == '-') || (c == '.')
			|| (c == '/') || (c == ' ')
			|| (c >= '0' && c <= '9'))
			return (1);
	else
		return (0);
}

//	validates ac & av
//	ac, chars in path, checks extension .cub
//	returns working fd
//	otherwise exits program
static int	ft_validate(ac, av)
{
	static int	i = 0;
	static int	fd = 0;
	if (ac != 2)
		ft_exit(ft_perror("unexpected argument count", EXIT_FAILURE), vars);
	while (av[1][i])
	{
		if (ft_isposixfile(c) == 0)
			ft_exit(ft_perror("invalid characters in file path", EXIT_FAILURE), vars);
		i++;
	}
	if ((av[1][i - 4]  != '.') || (av[1][i - 3] != 'c')
		|| (av[1][i - 2] != 'u') || (av[1][i - 1] != 'b'))
		ft_exit(ft_perror("invalid filename extension", EXIT_FAILURE), vars);
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		ft_exit(ft_perror("error", EXIT_FAILURE), vars);
	return (fd);
}

//	validates input (ac & av being correct and openable)
//	and initialise variables etc.
t_vars	ft_init_vars(ac, av)
{
		t_vars	*vars;

		vars = ft_calloc(1, sizeof(t_vars));
		vars->fd_map = ft_validate(ac, av);
		return (vars);
}
