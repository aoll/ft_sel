/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:20:49 by aollivie          #+#    #+#             */
/*   Updated: 2016/01/30 11:46:03 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_ck(const char *str1, const char *str2)
{
	if (str1 == NULL && str2 == NULL)
		return (0);
	if (str1 == NULL || str2 == NULL)
		return (0);
	if (str1[0] == '\0' || str2[0] == '\0')
		return (0);
	if (!str1 || !str2)
		return (0);
	return (1);
}

int			ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!str1 && !str2)
		return (1);
	if (!ft_ck(s1, s2))
		return (0);
	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (-1);
	}
	if (str1[i] == str2[i])
		return (1);
	else
		return (-1);
}
