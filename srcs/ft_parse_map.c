/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:04:26 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/28 13:40:24 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*	strict order & definition: 
no ./path
so ./path
we ./path
ea ./path
f rgb
c rgb

map **char
*/

static int	ft_validatepath(char *str, int id, t_map *mapdata, t_vars *vars)
{
	int		i;
	int		j;
	char	*target;

	(void) vars;
	target = NULL;
	if (id == 1)
			target = mapdata->no;
	else if (id == 2)
			target = mapdata->so;
	else if (id == 3)
			target = mapdata->ea;
	else if (id == 4)
			target = mapdata->we;
	else if (id == 5)
			target = mapdata->ceiling;
	else if (id == 6)
			target = mapdata->floor;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '	'))
		i++;
	if (str[i] == '\0' || str[i] == '\n')
		return (0);
	j = i;
	target = ft_calloc(1, _POSIX_PATH_MAX);
	while (str[i] && (ft_isposixfile(str[i])))
		str[++i] = target[++j];
	return (1);
}

static int	ft_read_line(char *line, t_map *mapdata, t_vars *vars)
{
	static int	count = 0;
	int			i;

	if (count == 6)
		return (6);
	i = 0;
	while (line[i])
	{
		if (line[0] && line[0] == '/' && line[1] && line[1] == '/')
			return (count);
		else if ((line[i] == 'N') && (line[i + 1] && line[i + 1] == 'O') && ft_validatepath(line + i + 2, 1, mapdata, vars))
					 printf("[%i]no texture\n", count++);
		else if ((line[i] == 'S') && (line[i + 1] && line[i + 1] == 'O') && ft_validatepath(line + i + 2, 2, mapdata, vars))
					 printf("[%i]so texture\n", count++);
		else if ((line[i] == 'W') && (line[i + 1] && line[i + 1] == 'E') && ft_validatepath(line + i + 2, 3, mapdata, vars))
					 printf("[%i]we texture\n", count++);
		else if ((line[i] == 'E') && (line[i + 1] && line[i + 1] == 'A') && ft_validatepath(line + i + 2, 4, mapdata, vars))
					 printf("[%i]ea texture\n", count++);
		else if ((line[i] == 'C') && line[i + 1] && ft_validatepath(line + i + 1, 5, mapdata, vars))
					 printf("[%i]c colour\n", count++);
		else if ((line[i] == 'F') && line[i + 1] && ft_validatepath(line + i + 1, 6, mapdata, vars))
					 printf("[%i]f colour\n", count++);
		i++;
	}
	return (count);
}

static void	ft_fetch_mapdata(t_map *mapdata, t_vars *vars)
{
	char	*buffer;
	int		i;

	(void) mapdata;
	buffer = get_next_line(vars->fd_map);
	while (buffer && ft_read_line(buffer, mapdata, vars) < 6)
	{
			free(buffer);
			buffer = get_next_line(vars->fd_map);
	}
	printf("found all textures, map is:\n");
	i = 0;
	while (buffer)
	{
		printf("[%i][%s]\n", i++, buffer);
		free(buffer);
		buffer = get_next_line(vars->fd_map);
	}
}

t_map		*ft_parse_map(t_vars *vars)
{
	t_map	*mapdata;
	(void) vars;

	mapdata = ft_calloc(1, sizeof(t_map));
	ft_fetch_mapdata(mapdata, vars);
	return (mapdata);
}
