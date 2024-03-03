/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_toscreen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:47:36 by mjochum           #+#    #+#             */
/*   Updated: 2024/03/03 12:18:32 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
/*	void	mlx_set_font(t_xvar *xvar, t_win_list *win, char *name)	*/
/*	int		mlx_string_put(t_xvar *xvar,t_win_list *win,
			       int x,int y,int color,char *string) */
//	writes lines one by one.
void	ft_write_toscreen(t_pixel position, char *str, t_vars *vars)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(str, '.');
	while (split[i])
	{
		mlx_string_put(vars->mlx, vars->mlx_win, position.x - 1, \
			position.y + (i * 15), 0x0, split[i]);
		mlx_string_put(vars->mlx, vars->mlx_win, position.x + 1, \
			position.y + (i * 15), 0x0, split[i]);
		mlx_string_put(vars->mlx, vars->mlx_win, position.x, \
			position.y - 1 + (i * 15), 0x0, split[i]);
		mlx_string_put(vars->mlx, vars->mlx_win, position.x, \
			position.y + 1 + (i * 15), 0x0, split[i]);
		mlx_string_put(vars->mlx, vars->mlx_win, position.x, \
			position.y + (i * 15), 0xefefef, split[i]);
		i++;
	}
	ft_free_split(split);
}
