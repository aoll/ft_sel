/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_tab_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 17:38:00 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/03 17:53:50 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select_tab_key.h"
/*
void	ft_()
{
	
	return ;
}
*/
void    ****ft_select_tab_key(void)
{
	void (****f);
	int i;
	int x;

	i = 0;
	if (!(f = malloc(sizeof(void ***) * 300)))
		return (NULL);
	while (i < 300)
	{
		if (!(f[i] = malloc(sizeof(void **) * 300)))
			return (NULL);
		x = 0;
		while (x < 300)
		{
			if (!(f[i][x] = malloc(sizeof(void *) * 300)))
				return (NULL);
			x++;
		}
		i++;
	}
	return (f);
}
