/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:29:35 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/30 14:22:11 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_perror(char *error, int retval)
{
	write(1, "Cub3d: ", 7);
	if (errno > 0)
		perror(error);
	else if (error)
		printf("Error: %s\n", error);
	return (retval);
}
