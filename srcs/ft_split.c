/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:31:03 by mjochum           #+#    #+#             */
/*   Updated: 2023/12/30 13:10:52 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static size_t	count_split(char const *s, char c)
{
	size_t	i;
	size_t	tabs;

	i = 0;
	tabs = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] && s[i] != c)
				i++;
			tabs++;
		}
	}
	return (tabs);
}

static size_t	count_letter(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		t;
	size_t		k;
	char		**tabs;

	t = count_split(s, c);
	i = 0;
	j = 0;
	k = 0;
	tabs = (char **) ft_calloc((t + 1), sizeof (char *));
	while (s[i] && t > j)
	{
		while (s[i] && s[i] == c)
			i++;
		tabs[j] = ft_calloc(count_letter(s + i, c) + 1, sizeof (char));
		while (s[i] && s[i] != c)
			tabs[j][k++] = s[i++];
		k = 0;
		j++;
	}
	return (tabs);
}
