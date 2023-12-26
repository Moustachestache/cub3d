/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:58:54 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/26 12:00:45 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	l;
	char	*buffer;

	l = 0;
	buffer = (char *) s;
	while (l < n)
	{
		buffer[l] = 0;
		l++;
	}
}
