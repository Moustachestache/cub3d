/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:04:26 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/28 17:24:09 by mjochum          ###   ########.fr       */
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

static int	ft_validatepath(char *str, char *target, t_map *mapdata, t_vars *vars)
{
	int		i;
	int		j;

	(void) mapdata;
	(void) vars;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '	'))
		i++;
	if (str[i] == '\0' || str[i] == '\n')
		return (0);
	j = -1;
	while (str[i] && str[i] != '\n' && (ft_isposixfile(str[i])))
		target[++j] = str[i++];
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
		else if ((line[i] == 'N') && (line[i + 1] && line[i + 1] == 'O') && ft_validatepath(line + i + 2, mapdata->no, mapdata, vars))
					 printf("[%i]no texture\n", count++);
		else if ((line[i] == 'S') && (line[i + 1] && line[i + 1] == 'O') && ft_validatepath(line + i + 2, mapdata->so, mapdata, vars))
					 printf("[%i]so texture\n", count++);
		else if ((line[i] == 'W') && (line[i + 1] && line[i + 1] == 'E') && ft_validatepath(line + i + 2, mapdata->we, mapdata, vars))
					 printf("[%i]we texture\n", count++);
		else if ((line[i] == 'E') && (line[i + 1] && line[i + 1] == 'A') && ft_validatepath(line + i + 2, mapdata->ea, mapdata, vars))
					 printf("[%i]ea texture\n", count++);
		else if ((line[i] == 'C') && line[i + 1] && ft_validatepath(line + i + 1, mapdata->ceiling, mapdata, vars))
					 printf("[%i]c colour\n", count++);
		else if ((line[i] == 'F') && line[i + 1] && ft_validatepath(line + i + 1, mapdata->floor, mapdata, vars))
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
	mapdata->no = ft_calloc(1, _POSIX_PATH_MAX);
	mapdata->so = ft_calloc(1, _POSIX_PATH_MAX);
	mapdata->ea = ft_calloc(1, _POSIX_PATH_MAX);
	mapdata->we = ft_calloc(1, _POSIX_PATH_MAX);
	mapdata->floor = ft_calloc(1, _POSIX_PATH_MAX);
	mapdata->ceiling = ft_calloc(1, _POSIX_PATH_MAX);
	ft_fetch_mapdata(mapdata, vars);
	return (mapdata);
}
