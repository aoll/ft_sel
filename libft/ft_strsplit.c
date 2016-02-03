/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 20:58:14 by aollivie          #+#    #+#             */
/*   Updated: 2015/11/24 17:04:36 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_y(char const *s, char c)
{
	size_t			y;
	size_t			i;

	i = 0;
	y = 1;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			y++;
		i++;
	}
	if (s[0] == c)
		y = (y - 1);
	return (y);
}

static char			**ft_cp(char **tab, char const *s, char c, size_t lin)
{
	size_t		y;
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	y = 0;
	if (tab)
	{
		while (y < lin)
		{
			while (s[i] && s[i] == c)
			{
				i++;
				j++;
			}
			while (s[i] != c && s[i])
				i++;
			tab[y] = ft_strsub(s, j, (i - j));
			j = i;
			y++;
		}
		tab[lin] = NULL;
	}
	return (tab);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		lin;

	if (!s)
		return (NULL);
	if (!c)
		return (NULL);
	lin = ft_y(s, c);
	tab = (char **)malloc(sizeof(char *) * (lin + 1));
	if (tab == NULL)
		return (NULL);
	tab = ft_cp(tab, s, c, lin);
	return (tab);
}
