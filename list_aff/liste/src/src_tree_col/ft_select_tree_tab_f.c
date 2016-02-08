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


#include "../../inc/ft_select_tree_col.h"
#include <term.h>

static void ft_putstr_space(int pad)
{
    while (pad)
    {
        ft_putchar(' ');
        pad--;
    }
    return ;
}

static void	ft_cancel_puts_mode(void)
{
    const char *res;

    if ((res = tgetstr("me", NULL)) == NULL)
	return (-1);
    ft_putstr(res);
	return;
}

static void ft_putstr_s_name_0(const char *s, int _pa)
{
    //  static int i = 0;

    //  i++;
//  printf("i_t_c_l_str == %d\n", t_c_l->i_l_str_max);
    ft_putstr(s);
    ft_putstr_space(_pa);
    return ;
}

static void ft_putstr_s_name_reverse_video(const char *s, int _pa)
{
    //  static int i = 0;
    const char *res;

    // i++;
    if ((res = tgetstr("mr", NULL)) == NULL)
	return (-1);
   ft_putstr(res);
//  printf("i_t_c_l_str == %d\n", t_c_l->i_l_str_max);
    ft_putstr(s);
    ft_cancel_puts_mode();
    ft_putstr_space(_pa);
    return ;
}

static void ft_putstr_s_name_underligne(const char *s, int _pa)
{
    // static int i = 0;
    const char *res;

    if ((res = tgetstr("us", NULL)) == NULL)
	return (-1);
    //  tputs(res, 0, putchar);
    ft_putstr(res);
    // i++;
//  printf("i_t_c_l_str == %d\n", t_c_l->i_l_str_max);
    ft_putstr(s);
    ft_cancel_puts_mode();
    ft_putstr_space(_pa);
    return ;
}

static void ft_putstr_s_name_reverse_underligne(const char *s, int _pa)
{
    //  static int i = 0;
    const char *res;

    //i++;
    if ((res = tgetstr("us", NULL)) == NULL)
	return (-1);
    ft_putstr(res);
    if ((res = tgetstr("mr", NULL)) == NULL)
	return (-1);
    ft_putstr(res);
//  printf("i_t_c_l_str == %d\n", t_c_l->i_l_str_max);
    ft_putstr(s);
    ft_cancel_puts_mode();
    ft_putstr_space(_pa);
    return ;
}

void	ft_select_tree_tab_f(void (***t)(const char *s, int _pa))
{
	if (!(*t = malloc(sizeof(void *) * 5)))
		return ;
	(*t)[4] = NULL;
	(*t)[0] = ft_putstr_s_name_0;
	(*t)[1] = ft_putstr_s_name_reverse_video;
	(*t)[2] = ft_putstr_s_name_underligne;
	(*t)[3] = ft_putstr_s_name_reverse_underligne;
	return ;
}
