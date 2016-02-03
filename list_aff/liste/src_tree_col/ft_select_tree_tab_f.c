/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_tree_tab_f.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 12:12:38 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/03 17:12:15 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/ft_select_tree_col.h"

static void ft_putstr_space(int pad)
{
    while (pad)
    {
        ft_putchar(' ');
        pad--;
    }
    return ;
}

static void ft_putstr_s_name(const char *s, int _pa)
{
    static int i = 0;

    i++;
//  printf("i_t_c_l_str == %d\n", t_c_l->i_l_str_max);
    ft_putstr(s);
    ft_putstr_space(_pa);
    return ;
}

void	ft_select_tree_tab_f(void (***t)(const char *s, int _pa))
{
	if (!(*t = malloc(sizeof(void *) * 5)))
		return ;
	(*t)[4] = NULL;
	(*t)[0] = ft_putstr_s_name;
	(*t)[1] = ft_putstr_s_name;
	(*t)[2] = ft_putstr_s_name;
	(*t)[3] = ft_putstr_s_name;
	return ;
}
