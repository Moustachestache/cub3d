/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <mjochum@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:57:27 by mjochum           #+#    #+#             */
/*   Updated: 2024/03/01 10:41:05 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_nblen(int n)
{
	int	buf_nb;
	int	i;

	buf_nb = n;
	i = 0;
	if (buf_nb < 0)
		i++;
	if (n == 0)
		return (1);
	while (buf_nb)
	{
		buf_nb = buf_nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*tab;

	i = ft_nblen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tab = ft_calloc(i + 1, sizeof(char));
	if (!tab)
		return (NULL);
	if (n == 0)
		tab[0] = '0';
	if (n < 0)
	{
		tab[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		tab[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (tab);
}
