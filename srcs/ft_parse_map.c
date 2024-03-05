/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:04:26 by mjochum           #+#    #+#             */
/*   Updated: 2024/03/05 16:37:21 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*ft_validatepath(char *str, t_map *mapdata, t_vars *vars)
{
	int		i;
	int		j;
	char	*target;

	(void) mapdata;
	(void) vars;
	i = 0;
	while (str[i] && (ft_isspace(str[i])))
		i++;
	if (str[i] == '\0' || str[i] == '\n')
		return (NULL);
	j = -1;
	target = ft_calloc(1, _POSIX_PATH_MAX);
	while (str[i] && str[i] != '\n' && (ft_isposixfile(str[i])))
		target[++j] = str[i++];
	return (target);
}

static int	ft_validatecolour(char *str, unsigned int *target, \
	t_map *mapdata, t_vars *vars)
{
	int		i;
	int		j;
	char	**temp;

	(void) mapdata;
	(void) vars;
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
		if (i > 255 || i < 0)
			vars->err = ft_perror("Color Value Outside Of Range", 1);
		*target += i << (16 - (j * 8));
	}
	ft_free_split(temp);
	return (1);
}

static int	ft_read_line(char *line, t_map *mapdata, t_vars *vars)
{
	int			i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (0);
	if (!ft_strncmp(line + i, "NO", 2) && !mapdata->no)
		mapdata->no = ft_validatepath(line + i + 2, mapdata, vars);
	else if (!ft_strncmp(line + i, "WE", 2) && !mapdata->we)
		mapdata->we = ft_validatepath(line + i + 2, mapdata, vars);
	else if (!ft_strncmp(line + i, "SO", 2) && !mapdata->so)
		mapdata->so = ft_validatepath(line + i + 2, mapdata, vars);
	else if (!ft_strncmp(line + i, "EA", 2) && !mapdata->ea)
		mapdata->ea = ft_validatepath(line + i + 2, mapdata, vars);
	else if (!ft_strncmp(line + i, "DO", 2) && !mapdata->door)
		mapdata->door = ft_validatepath(line + i + 2, mapdata, vars);
	else if (!ft_strncmp(line + i, "XO", 2) && !mapdata->sprite)
		mapdata->sprite = ft_validatepath(line + i + 2, mapdata, vars);
	else if (line[i] == 'C' && mapdata->ceiling == 0)
		ft_validatecolour(line + i + 2, &mapdata->ceiling, mapdata, vars);
	else if (line[i] == 'F' && mapdata->floor == 0)
		ft_validatecolour(line + i + 2, &mapdata->floor, mapdata, vars);
	free(line);
	return (1);
}

static int	ft_fetch_map(char *buffer, t_map *mapdata, t_vars *vars)
{
	int		temp;
	int		i;
	int		err;

	err = 0;
	if (!buffer)
		ft_exit(ft_perror("No Map Information Found", 1), vars);
	mapdata->map = ft_calloc(4096, sizeof(char));
	i = -1;
	while (buffer && err == 0)
	{
		temp = ft_strlen(buffer);
		if (mapdata->width < temp)
			mapdata->width = temp;
		buffer[temp - 1] = '\0';
		mapdata->map[++i] = buffer;
		buffer = get_next_line(vars->fd_map);
		err += ft_validatemapbuffer(buffer);
	}
	if (err > 0)
	{
		ft_perror("Invalid Characters In Map Buffer", EXIT_FAILURE);
		//ft_flushgnl(buffer, vars);
		free(buffer);
	}
	mapdata->height = i;
	return (err);
}

t_map	*ft_parse_map(t_vars *vars)
{
	t_map	*mapdata;
	char	*buffer;

	mapdata = vars->mapdata;
	mapdata = ft_calloc(1, sizeof(t_map));
	buffer = get_next_line(vars->fd_map);
	while (buffer && ft_read_line(buffer, mapdata, vars))
		buffer = get_next_line(vars->fd_map);
	vars->err = ft_fetch_map(buffer, mapdata, vars);
	return (mapdata);
}
