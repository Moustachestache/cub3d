/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:11:41 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/02 14:45:38 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	l;

	l = 0;
	if (n == 0)
		return (0);
	while (s1[l] && s2[l] && l < n)
	{
		if (s1[l] != s2[l])
			return ((unsigned char) s1[l] - s2[l]);
		l++;
	}
	if ((s1[l] != '\0' || s2[l] != '\0') && l < n)
		return ((unsigned char) s1[l] - s2[l]);
	return (0);
}
