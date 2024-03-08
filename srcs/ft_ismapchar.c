/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismapchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <mjochum@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:22:02 by mjochum           #+#    #+#             */
/*   Updated: 2024/03/05 15:37:20 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_ismapchar_re(char c)
{
	if (c == '\n' || c == '0' || c == '1' || c == ' ' || \
			c == 'D' || c == 'd' || \
			c == 's' || \
			c == 'S' || c == 'N' || c == 'W' || c == 'E')
		return (0);
	return (1);
}