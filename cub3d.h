/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:49:30 by mjochum           #+#    #+#             */
/*   Updated: 2024/01/01 15:11:35 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <limits.h>
# include "mlx/mlx.h"
# include "structures.h"

# define BUFFER_SIZE 1000
# define W_HEIGHT 900
# define W_WIDTH 1600

size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_line(char *save);
char	*ft_save(char *save);
char	*ft_read_and_save(int fd, char *save);
char	*get_next_line(int fd);
t_vars	*ft_init_vars(int ac, char *av[]);
char	*get_next_line(int fd);
void	ft_exit(int exit_value, t_vars *vars);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_perror(char *error, int retval);
t_map	*ft_parse_map(t_vars *vars);
int		ft_isposixfile(char c);
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
void	ft_free_split(char **split);
int		ft_keyhook(int keycode, t_vars *vars);

#endif
