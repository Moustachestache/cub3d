/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:24:06 by mjochum           #+#    #+#             */
/*   Updated: 2024/03/01 11:26:51 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_render_background(t_image *image, t_vars *vars)
{
	int	half;
	int	y;
	int	x;

	y = -1;
	x = -1;
	half = W_HEIGHT / 2;
	(void) ft_darken;
	while (++y <= half)
	{
		while (++x < W_WIDTH)
			ft_img_pix_put((t_pixel){x, y, vars->mapdata->ceiling}, image);
		x = -1;
	}
	y = W_HEIGHT;
	while (y-- >= half)
	{
		while (++x < W_WIDTH)
			ft_img_pix_put((t_pixel){x, y, vars->mapdata->floor}, image);
		x = -1;
	}
}

static void	ft_init_background(t_image *bg, t_vars *vars)
{
	bg->width = W_WIDTH;
	bg->height = W_HEIGHT;
	bg->image = mlx_new_image(vars->mlx, bg->width, bg->height);
	if (bg->image == NULL)
		ft_exit(ft_perror("Could Not create Background", EXIT_FAILURE), vars);
	bg->addr = mlx_get_data_addr(bg->image, &bg->bpp, &bg->len, &bg->endian);
	ft_render_background(bg, vars);
}

//	add error handling if texture no exist
static void	ft_init_logo(t_vars *vars)
{
	vars->logo.image = mlx_xpm_file_to_image(vars->mlx, \
		"./assets/cub3d_logo.xpm", &vars->logo.height, &vars->logo.width);
	if (vars->logo.image == NULL)
		ft_exit(ft_perror("Game Logo Was Deleted LOL??", EXIT_FAILURE), vars);
	vars->logo.addr = mlx_get_data_addr(vars->logo.image, \
		&vars->logo.bpp, &vars->logo.len, &vars->logo.endian);
}

static int	ft_create_texture(t_image *texture, char *path, t_vars *vars)
{
	if (!path || path[0] == '\0')
		ft_perror("No Path To Texture", 0);
	texture->image = mlx_xpm_file_to_image(vars->mlx, path, \
		&texture->height, &texture->width);
	if (!texture->image)
	{
		ft_perror("Error loading texture", 0);
		texture->image = mlx_xpm_file_to_image(vars->mlx, \
			"./assets/default.xpm", &texture->height, &texture->width);
	}
	texture->addr = mlx_get_data_addr(texture->image, \
		&texture->bpp, &texture->len, &texture->endian);
	if (texture->image == NULL)
		ft_exit(ft_perror("Error Loading Texture", \
			EXIT_FAILURE), vars);
	if (texture->height != T_SIZE || texture->width != T_SIZE)
		ft_exit(ft_perror("Texture Size Should be 128*128", \
			EXIT_FAILURE), vars);
	return (0);
}

void	ft_init_textures(t_map *map, t_vars *vars)
{
	ft_init_logo(vars);
	ft_init_background(&vars->background, vars);
	ft_create_texture(&vars->tdefault, "./assets/default.xpm", vars);
	map->texture = ft_calloc(5, sizeof(t_image));
	ft_create_texture(&map->texture[0], map->no, vars);
	ft_create_texture(&map->texture[1], map->so, vars);
	ft_create_texture(&map->texture[2], map->ea, vars);
	ft_create_texture(&map->texture[3], map->we, vars);
	if (map->door)
		ft_create_texture(&map->texture[4], map->door, vars);
	if (map->sprite)
		ft_init_sprite(map->sprite, vars);
	ft_render_minimap(&vars->minimap, vars);
	ft_render_graphfps(vars);
}
