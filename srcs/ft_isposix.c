/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isposix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:18:37 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/30 10:56:42 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//	checks if the str conforms to the POSIX path character norm & file character norm
//	https://www.ibm.com/docs/en/zos/2.1.0?topic=locales-posix-portable-file-name-character-set
int	ft_isposixfile(char c)
{
	static char	previous;

	if (((c >= 32 && c <= 47)) && previous == '/')
	{
		previous = c;
		return (1);
	}
	else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_') || (c == '-') || (c == '.') || (c == '/') || (c >= '0' && c <= '9'))
	{
		previous = c;
		return (1);
	}
	else
	{
		previous = 0;
		return (0);
	}
}

