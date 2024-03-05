/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawslice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:27:57 by mjochum           #+#    #+#             */
/*   Updated: 2024/03/01 10:14:51 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//	int x			= which slice it is on the x axis
//	float distance	= calculated distance
//	float intersect	= where we hit the texture

t_image	*ft_set_texture(t_vars *vars, t_camera *camera)
{
	t_image	*texture;

	camera->sprite = vars->mapdata->map[camera->mapy][camera->mapx];
	texture = NULL;
	/*if (camera->sprite == '0')
		return (&vars->mapdata->texture[6]);*/
	if (camera->sprite == 's')
		texture = &vars->mapdata->stexture[vars->frame];
	/*else if (camera->sprite == 'd')
		texture = NULL;*/
	else if (camera->sprite == 'D')
		texture = &vars->mapdata->texture[4];
	else if (camera->sprite == '1')
	{
		if (camera->side == 'N')
			texture = &vars->mapdata->texture[0];
		else if (camera->side == 'E')
			texture = &vars->mapdata->texture[1];
		else if (camera->side == 'S')
			texture = &vars->mapdata->texture[2];
		else if (camera->side == 'W')
			texture = &vars->mapdata->texture[3];
	}
	return (texture);
}

void	ft_drawslice(int x, t_camera *camera, \
	t_image *texture, t_vars *vars)
{
	t_pixel		pixel;
	int			height;
	float		error[2];

	height = W_HEIGHT / camera->wall_dist;
	texture = ft_set_texture(vars, camera);
	pixel = (t_pixel){x, (W_HEIGHT / 2) - (height / 2), 0xff00ff};
	error[0] = (float)T_SIZE / (float)height;
	error[1] = 0;
	while (height > 0)
	{
		pixel.colour = ft_fetch_imgcolour(texture, \
			(int)(T_SIZE * camera->intersect), error[1]);
		ft_img_pix_put(pixel, vars->buffer);
		height--;
		pixel.y++;
		error[1] += error[0];
	}
}
