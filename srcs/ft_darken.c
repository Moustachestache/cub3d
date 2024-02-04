/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darken.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:17:33 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/02 23:34:39 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
static unsigned char	ft_getfactor(unsigned char r, unsigned char g, unsigned char b)
{
	char	smallest;

	smallest = r;
	if (r > g)
		smallest = g;
	if (g > b)
		smallest = b;
	return (255 / smallest);
}

static unsigned int	ft_darken_ceiling(unsigned int colour)
{
	static unsigned char	red;
	static unsigned char	green;
	static unsigned char	blue;
	static unsigned char	factor;

	if (colour == 0)
		return (0);
	else if (factor == 0 && (red | green | blue == 0))
	{
		red = colour >> 16;
		green = colour >> 8;
		blue = colour >> 0;
		factor = ft_getfactor(red, green, blue);
	}
	if (factor == 0)
		return (0);
	red -= red / factor;
	green -= green / factor;
	blue -= blue / factor;
	return ((red  << 16) + (green  << 8) + blue);
}

static unsigned int	ft_darken_floor(unsigned int colour)
{
	static unsigned char	red;
	static unsigned char	green;
	static unsigned char	blue;
	static unsigned char	factor;


	if (colour == 0)
		return (0);
	else if (factor == 0 && (red | green | blue == 0))
	{
		red = colour >> 16;
		green = colour >> 8;
		blue = colour >> 0;
		factor = ft_getfactor(red, green, blue);
	}
	if (factor == 0)
		return (0);
	red -= red / factor;
	green -= green / factor;
	blue -= blue / factor;
	return ((red  << 16) + (green  << 8) + blue);
}


unsigned int	ft_darken(unsigned int colour, char id)
{
	if (id == 'c')
		return (ft_darken_ceiling(colour));
	else
		return (ft_darken_floor(colour));
}
