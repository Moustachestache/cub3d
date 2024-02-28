/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <mjochum@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:31:23 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/28 15:22:01 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_writetosprite(int counter, t_image *target, t_image *source, t_vars *vars)
{
	t_pixel		offset;
	int			i;
	int			j;

	i = 0;
	j = 0;
	(void) vars;
	target->width = T_SIZE;
	target->height = T_SIZE;
	target->image = mlx_new_image(vars->mlx, target->width, target->height);
	target->addr = mlx_get_data_addr(target->image, &target->bpp, &target->len, &target->endian);
	offset = (t_pixel){0, 0, 0};
	if (counter == 1)
		offset.x = T_SIZE;
	else if (counter == 2)
		offset.y = T_SIZE;
	else if (counter == 3)
		offset = (t_pixel){T_SIZE, T_SIZE, 0};
	while (i < target->width)
	{
		while (j < target->height)
		{
			ft_img_pix_put_alpha((t_pixel){i, j, ft_fetch_imgcolour(source, offset.x + i, offset.y + j)}, target);
			j++;
		}
		j = 0;
		i++;
	}
}

void		ft_init_sprite(char *path, t_vars *vars)
{
	t_image		*temp;
	t_map		*map;
	static int	i = -1;

	map = vars->mapdata;
	temp = ft_calloc(1, sizeof(t_image));
	map->stexture = ft_calloc(4, sizeof(t_image));
	if (map->stexture == NULL)
		ft_exit(ft_perror("Error Initialising Sprite", EXIT_FAILURE), vars);
	temp->image = mlx_xpm_file_to_image(vars->mlx, path, &temp->height, &temp->width);
	if (temp->image == NULL)
		ft_exit(ft_perror("Sprite Remains Un-initialised", EXIT_FAILURE), vars);
	temp->addr = mlx_get_data_addr(temp->image, &temp->bpp, &temp->len, &temp->endian);
	//	test
	//ft_put_img((t_pixel){W_WIDTH / 2, W_HEIGHT / 2, 0}, temp, &vars->background);
	while (++i < 4)
		ft_writetosprite(i, &map->stexture[i], temp, vars);
	mlx_destroy_image(vars->mlx, temp->image);
}
