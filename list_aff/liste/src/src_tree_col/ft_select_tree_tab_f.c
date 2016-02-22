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


void	ft_putstr_n(char *s, int i)
{
    while (i)
	{
	    ft_putchar(*s);
	    *s++;
	    i--;
	}
    ft_putstr("\".\"  ");
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
    if (ft_strlen(s) <= 20)
	{
	    ft_putstr(s);
	    ft_putstr_space(_pa);
	}
    else
	ft_putstr_n(s, 20);
    return ;
}

static void ft_putstr_s_name_reverse_video(const char *s, int _pa)
{
    const char *res;

    if ((res = tgetstr("ue", NULL)) == NULL)
	return (-1);
    ft_putstr(res);
    if ((res = tgetstr("mr", NULL)) == NULL)
	return (-1);
   ft_putstr(res);
   if (ft_strlen(s) <= 20)
       {
	   ft_putstr(s);
	   ft_cancel_puts_mode();
	   ft_putstr_space(_pa);
       }
   else
       {
	   ft_putstr_space(25);
	   ft_cancel_puts_mode();
       }
    return ;
}

static void ft_putstr_s_name_underligne(const char *s, int _pa)
{
    const char *res;

    if ((res = tgetstr("us", NULL)) == NULL)
	return (-1);
    ft_putstr(res);
    if (ft_strlen(s) <= 20)
	{
	    ft_putstr(s);
	    ft_cancel_puts_mode();
	    ft_putstr_space(_pa);
	}
    else
	{
	    ft_putstr_space(25);
	    ft_cancel_puts_mode();
	}
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
    if (ft_strlen(s) <= 20)
	{
	    ft_putstr(s);
	    ft_cancel_puts_mode();
	    ft_putstr_space(_pa);
	}
    else
	ft_putstr_space(25);
    //ft_putstr(s);
    ft_cancel_puts_mode();
    //ft_putstr_space(_pa);
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
