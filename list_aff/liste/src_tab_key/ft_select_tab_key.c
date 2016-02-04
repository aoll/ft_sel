/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_tab_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 17:38:00 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/04 17:35:28 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select_tab_key.h"

int	ft_p_test(void)
{
	printf("%s\n", "PAS ASSIGNE");
	return (0);
}

void    ft_select_tab_key_init(int (* ****f)(void))
{
	(*f)[1][1][1] = ft_select_key_up;
	(*f)[1][1][2] = ft_select_key_down;
	(*f)[1][1][3] = ft_select_key_right;
	(*f)[1][1][4] = ft_select_key_left;

	(*f)[2][1][3] = ft_select_key_return;
	(*f)[3][2][5] = ft_select_key_space;
	(*f)[1][2][5] = ft_select_key_echap;
	(*f)[5][2][5] = ft_select_key_sup_del;

	(*f)[1][1][6] = ft_select_key_sup_del;
	(*f)[4][1][6] = ft_select_key_sup_del;
}

void    ft_select_tab_key_new(int (* ****f)(void))
{
	int z;
	int y;
	int x;
	
	z = 0;
	y = 0;
	x = 0;
	*f = malloc(sizeof(void ***) * 6);
	while (z < 6)
	{
		(*f)[z] = malloc(sizeof(void **) * 3);
		y = 0;
		while (y < 3)
		{
			(*f)[z][y] = malloc(sizeof(void *) * 7);
			x = 0;
			while (x < 7)
			{
					(*f)[z][y][x] = ft_p_test;
					x++;
			}
			y++;
		}
		z++;
	}
	ft_select_tab_key_init(f);
}
