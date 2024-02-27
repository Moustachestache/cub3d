/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <mjochum@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:31:23 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/27 18:46:26 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_sprite(char *path, t_vars *vars)
{
	t_image		*temp;
	t_map		*map;
	static int	i;

	map = vars->mapdata;
	temp = ft_calloc(1, sizeof(t_image));
	map->stexture = ft_calloc(4, sizeof(t_image));
	if (map->stexture == NULL)
		ft_exit(ft_perror("Error Initialising Sprite", EXIT_FAILURE), vars);
	temp->image = mlx_xpm_file_to_image(vars->mlx, path, &temp->height, &temp->width);
	if (temp->image == NULL)
		ft_exit(ft_perror("Sprite Remains Un-initialised", EXIT_FAILURE), vars);
	temp->addr = mlx_get_data_addr(temp->image, &temp->bpp, &temp->len, &temp->endian);
	printf("init sprite ok?\n");
	//	test
	//	ft_put_img((t_pixel){W_WIDTH / 2, W_HEIGHT / 2, 0}, temp, &vars->background);
	while (i < 4)
	{
		
	}
}
