/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:31:29 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/12 19:16:45 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	l;
	char	*dest_buffer;
	char	*src_buffer;

	if (!src && !dest)
		return (dest);
	dest_buffer = (char *) dest;
	src_buffer = (char *) src;
	l = 0;
	while (l < n && dest_buffer[l] && src_buffer[l])
	{
		dest_buffer[l] = src_buffer[l];
		l++;
	}
	return (dest);
}
