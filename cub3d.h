/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:49:30 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/24 12:12:03 by mjochum          ###   ########.fr       */
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
# define W_HEIGHT 600
# define W_WIDTH 800
# define FOV 60
# define CELL_SIZE 5
# define T_SIZE 128
# define A_COLOR 0x00ff00

size_t			ft_strlen(char *str);
char			*ft_strchr(char *s, int c);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_get_line(char *save);
char			*ft_save(char *save);
char			*ft_read_and_save(int fd, char *save);
char			*get_next_line(int fd);
t_vars			*ft_init_vars(int ac, char *av[]);
char			*get_next_line(int fd);
void			ft_exit(int exit_value, t_vars *vars);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_bzero(void *s, size_t n);
int				ft_perror(char *error, int retval);
t_map			*ft_parse_map(t_vars *vars);
t_image			*ft_init_image(t_vars *vars);
int				ft_isposixfile(char c);
int				ft_atoi(const char *nptr);
char			**ft_split(char const *s, char c);
void			ft_free_split(char **split);
int				ft_keyhook(int keycode, t_vars *vars);
int				ft_validate_mapinfo(t_map *mapdata, t_vars *vars);
void			ft_img_pix_put(t_pixel pixel, t_image *image);
int				ft_render(t_vars *vars);
void			ft_img_flush(t_vars *vars);
void			ft_drawline(t_pixel start, t_pixel dest, \
	t_image *buffer, t_vars *vars);
void			ft_render_minimap(t_image *image, t_vars *vars);
void			ft_update_angle(int *angle, int add, t_vars *vars);
t_pixel			ft_transform_pixel(t_pixel pixel, \
	float increase, float vector);
float			ft_deg_to_rad(float a);
void			ft_transform_player(float *x, float *y, \
	float increase, float vector);
void			ft_player_init(int x, int y, char mapinfo, t_vars *vars);
void			ft_write_toscreen(t_pixel position, char *str, t_vars *vars);
void			ft_init_textures(t_map *mapdata, t_vars *vars);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_isspace(char c);
void			ft_put_img(t_pixel pos, t_image *image, t_image *buffer);
unsigned int	ft_darken(unsigned int colour, char id);
unsigned int	ft_fetch_imgcolour(t_image *image, int x, int y);
void			ft_drawslice(int x, t_camera *camera, \
	t_image *texture, t_vars *vars);
void			ft_drawplayer(t_player *player, t_vars *vars);
int				ft_map_validation(t_vars *vars);
char			*ft_strdup(const char *s);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_draw_rays(t_vars *vars);
void			*ft_memset(void *s, int c, size_t n);

#endif
