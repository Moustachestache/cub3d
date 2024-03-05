/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validatemapbuffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <mjochum@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:27:49 by mjochum           #+#    #+#             */
/*   Updated: 2024/03/05 15:38:08 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_validatemapbuffer(char *str)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (str[i])
	{
		err += ft_ismapchar_re(str[i]);
		i++;
	}
	return (err);
}
