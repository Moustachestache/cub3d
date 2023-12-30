/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:00:55 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/30 10:58:21 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_vars t_vars;
typedef struct s_map t_map;
typedef struct s_player t_player;
typedef struct s_node t_node;

typedef struct s_vars {
	int			fd_map;
	t_map		*mapdata;
	t_player	*player;
}				t_vars;

typedef struct s_map {
	int		floor;
	int		ceiling;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	t_node	**map;
}			t_map
;
typedef struct s_player {
	char	start;
	int		xstart;
	int		ystart;
}		t_player;

#endif
