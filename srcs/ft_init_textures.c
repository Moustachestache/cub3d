/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:24:06 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/01 23:18:00 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//	add error handling if texture no exist
static void		ft_init_logo(t_vars *vars)
{
	int		height;
	int		width;

	vars->logo.image = mlx_xpm_file_to_image(vars->mlx, "./assets/cub3d_logo.xpm", &height, &width);
	vars->logo.addr = mlx_get_data_addr(vars->logo.image, &vars->logo.bpp, &vars->logo.len, &vars->logo.endian);
}

static int		ft_create_texture(t_image *texture, char *path, t_vars *vars)
{
	int		height;
	int		width;

printf("ft-texture: [%s]\n", path);
	if (!path || path[0] == '\0')
		ft_exit(ft_perror("No Path To Texture", EXIT_FAILURE), vars);
	texture->image = mlx_xpm_file_to_image(vars->mlx, path, &height, &width);
	if (!texture->image)
	{
		ft_perror("Error loading texture", 0);
		texture->image = mlx_xpm_file_to_image(vars->mlx, "./assets/default.xpm", &height, &width);
	}
	texture->addr = mlx_get_data_addr(texture->image, &texture->bpp, &texture->len, &texture->endian);
	if (texture->image == NULL)
		ft_exit(ft_perror("Error Loading Texture", EXIT_FAILURE), vars);
	if (height != T_SIZE || width != T_SIZE)
		ft_exit(ft_perror("Texture Size Should be 128*128", EXIT_FAILURE), vars);
	return (0);
}

void		ft_init_textures(t_map *mapdata, t_vars *vars)
{
	ft_init_logo(vars);
	mapdata->texture = ft_calloc(6, sizeof(t_image));
	ft_create_texture(&mapdata->texture[0], mapdata->no, vars);
	ft_create_texture(&mapdata->texture[1], mapdata->so, vars);
	ft_create_texture(&mapdata->texture[2], mapdata->ea, vars);
	ft_create_texture(&mapdata->texture[3], mapdata->we, vars);
	//	door texture
	if (mapdata->door)
		ft_create_texture(&mapdata->texture[4], mapdata->door, vars);
	//	sprite texture
	if (mapdata->sprite)
		ft_create_texture(&mapdata->texture[5], mapdata->sprite, vars);
}
