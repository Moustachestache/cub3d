/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:57:54 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/26 11:58:17 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (!(size == (nmemb * size / nmemb)))
		return (NULL);
	tab = (void *) malloc((nmemb) * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, nmemb * size);
	return (tab);
}
