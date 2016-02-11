/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_tab_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 17:38:00 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/04 17:44:07 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_select_tab_key.h"

static int	ft_p_test(t_config_liste **t_c_l, t_tree_col **t_t_c)
{
    if (!*t_c_l || !*t_t_c)
	return (-1);
    ft_putstr("PAS ASSIGNE");
    return (1);
}

static void    ft_select_tab_key_init(int (* ****f)(t_config_liste **t_c_l, t_tree_col **t_t_c))
{
	(*f)[1][1][1] = ft_select_key_up;
	(*f)[1][1][2] = ft_select_key_down;
	(*f)[1][1][3] = ft_select_key_right;
	(*f)[1][1][4] = ft_select_key_left;

	(*f)[2][2][5] = ft_select_key_return;
	(*f)[3][2][5] = ft_select_key_space;
	(*f)[1][2][5] = ft_select_key_echap;
	(*f)[5][2][5] = ft_select_key_sup_del;

	(*f)[1][1][6] = ft_select_key_sup_del;
	(*f)[4][2][5] = ft_select_key_sup_del;
}

int    ft_select_tab_key_new(int (* ****f)(t_config_liste **t_c_l, t_tree_col **t_t_c))
{
	int z;
	int y;
	int x;
	
	z = 0;
	y = 0;
	x = 0;
	if (!(*f = malloc(sizeof(void ***) * 6)))
		return (0);
	while (z < 6)
	{
		if (!((*f)[z] = malloc(sizeof(void **) * 3)))
			return (0);
		y = 0;
		while (y < 3)
		{
			if (!((*f)[z][y] = malloc(sizeof(void *) * 7)))
				return (0);
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
	return (1);
}

int    ft_select_tab_key_free(int (* ****f)(t_config_liste **t_c_l, t_tree_col **t_t_c))
{
	int z;
	int y;
	int x;
	
	z = 0;
	y = 0;
	x = 0;
	while (z < 6)
	{
		
		y = 0;
		while (y < 3)
		{
		    //	if (!(
		    //		return (0);
			x = 0;
			while (x < 7)
			{
			    //free((f)[z][y][x]);
			    (*f)[z][y][x] = NULL;
			    x++;
			}
			free((*f)[z][y]);
			(*f)[z][y] = NULL;
			y++;
		}
		free((*f)[z]);
		(*f)[z] = NULL;
		z++;
	}
	free(*f);
	(*f) = NULL;
	return (1);
}
