/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darken.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:17:33 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/26 14:18:51 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
/*static unsigned char	ft_getfactor(unsigned char r, \
	unsigned char g, unsigned char b)
{
	(void) r;
	(void) g;
	(void) b;
	return (13);
}*/

static unsigned int	ft_darken_ceiling(unsigned int colour)
{
	static unsigned char	red;
	static unsigned char	green;
	static unsigned char	blue;
	static unsigned char	factor = 13;

	if (colour == 0)
		return (0);
	else if (factor == 0 && (red | green | blue == 0))
	{
		red = colour >> 16;
		green = colour >> 8;
		blue = colour >> 0;
	}
	if (factor == 0)
		return (0);
	red -= red / factor;
	green -= green / factor;
	blue -= blue / factor;
	return ((red << 16) + (green << 8) + blue);
}

static unsigned int	ft_darken_floor(unsigned int colour)
{
	static unsigned char	red;
	static unsigned char	green;
	static unsigned char	blue;
	static unsigned char	factor = 13;

	if (colour == 0)
		return (0);
	else if (factor == 0 && (red | green | blue == 0))
	{
		red = colour >> 16;
		green = colour >> 8;
		blue = colour >> 0;
	}
	if (factor == 0)
		return (0);
	red -= red / factor;
	green -= green / factor;
	blue -= blue / factor;
	return ((red << 16) + (green << 8) + blue);
}

unsigned int	ft_darken(unsigned int colour, char id)
{
	return (1);
	if (id == 'c')
		return (ft_darken_ceiling(colour));
	else
		return (ft_darken_floor(colour));
}
