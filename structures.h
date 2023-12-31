/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:00:55 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/31 13:30:49 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_vars t_vars;
typedef struct s_map t_map;
typedef struct s_player t_player;

typedef struct s_vars {
	int			fd_map;
	void		*mlx;
	void		*mlx_win;
	t_map		*mapdata;
	t_player	*player;
}				t_vars;

typedef struct s_map {
	int		height;
	int		width;
	int		floor;
	int		ceiling;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	**map;
}			t_map
;
typedef struct s_player {
	char	start;
	int		xstart;
	int		ystart;
}		t_player;

#endif
