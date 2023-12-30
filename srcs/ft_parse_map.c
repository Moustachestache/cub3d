/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:04:26 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/30 23:00:01 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

static int	ft_validatecolour(char *str, int *target, t_map *mapdata, t_vars *vars)
{
	int		i;
	int		j;
	char	**temp;

	(void) mapdata;
	i = 0;
	temp = NULL;
	while (str[i] && (str[i] == ' ' || str[i] == '	'))
		i++;
	if (str[i] == '\0' || str[i] == '\n')
		return (0);
	temp = ft_split(str + i, ',');
	j = -1;
	while (temp[++j])
	{
		i = ft_atoi(temp[j]);
			if (i > 255)
				ft_exit(ft_perror("Color Value Superior To 255", 1), vars);
		*target += i << (16 - (j * 8));
	}
	ft_free_split(temp);
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
		else if ((line[i] == 'C') && line[i + 1] && ft_validatecolour(line + i + 1, &mapdata->ceiling, mapdata, vars))
					 printf("[%i]c colour\n", count++);
		else if ((line[i] == 'F') && line[i + 1] && ft_validatecolour(line + i + 1, &mapdata->floor, mapdata, vars))
					 printf("[%i]f colour\n", count++);
		i++;
	}
	return (count);
}

static void	ft_fetch_map(t_map *mapdata, t_vars *vars)
{
	//	here map is taked
	char	*buffer;
	int		temp;
	int		i;

	buffer = get_next_line(vars->fd_map);
	//	skip shit lines
	while (buffer && buffer[0] == '\n')
	{
		free(buffer);
		buffer = get_next_line(vars->fd_map);
	}
	if (!buffer)
		ft_exit(ft_perror("No Map Information Found", 1), vars);
	//	probably later make the map a bunch of t_nodes but i cant see why thatd be needed right now
	//	a proble; for future me:
	mapdata->map = ft_calloc(4096, sizeof(char));
	i = -1;
	while (buffer)
	{
		temp = ft_strlen(buffer);
		if (mapdata->width < temp)
			mapdata->width = temp;
		buffer[temp - 1] = '\0';
		mapdata->map[++i] = buffer;
		buffer = get_next_line(vars->fd_map);
	}
	mapdata->height = i;
}

t_map		*ft_parse_map(t_vars *vars)
{
	t_map	*mapdata;
	char	*buffer;

	mapdata = ft_calloc(1, sizeof(t_map));
	mapdata->no = ft_calloc(1, _POSIX_PATH_MAX);
	mapdata->so = ft_calloc(1, _POSIX_PATH_MAX);
	mapdata->ea = ft_calloc(1, _POSIX_PATH_MAX);
	mapdata->we = ft_calloc(1, _POSIX_PATH_MAX);
//	here gets map info (textures, colours)
	buffer = get_next_line(vars->fd_map);
	while (buffer && ft_read_line(buffer, mapdata, vars) < 6)
	{
			free(buffer);
			buffer = get_next_line(vars->fd_map);
	}
	free(buffer);
//	here get map and save into mapdata
	ft_fetch_map(mapdata, vars);
	return (mapdata);
}
