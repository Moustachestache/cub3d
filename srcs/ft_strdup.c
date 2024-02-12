/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:22:14 by mjochum           #+#    #+#             */
/*   Updated: 2024/02/11 21:24:27 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//	tremy be blessed
char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	length;
	char	*tab;

	length = ft_strlen((char *)s);
	i = 0;
	tab = ft_calloc(length + 1, sizeof(char));
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
	return (tab);
}
