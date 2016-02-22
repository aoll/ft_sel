/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:39:54 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/04 18:33:05 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_select.h"

int	ft_select_print_out(int *ck, int *ctrl_z, t_init **init)
{
    char *goto_str;//, *clear_str; // doit etre free!!!!!
   
  goto_str = tgetstr("cm", NULL);    
    if ((*ck) || (*ctrl_z) > 1000000)
    {
	if ((*ctrl_z) > 1000000)
	    ft_tree_col_init_tab(&((*init)->t_t_c->ptr_tab), &(*init)->t_l, (*init)->t_c_l->i_nb_ligne_col, (*init)->t_c_l->i_nb_col);
	ft_putstr(tgoto(goto_str, 0, 0));//, stdout);
	ft_putstr("\e[1;1H\e[2J"); //clear
	ft_select_tree_print((*init)->t_t_c, (const t_config_liste*)(*init)->t_c_l, (*init)->t);
	(*ck) = 0;
	(*ctrl_z) = 0;
    }  
    return (0);
}

int	ft_term_print_too_small(short int *i, short int *j)
{
    if ((*i) == 1)
	{
	    if ((*j) == 1)
		{
		    ft_putstr(tgoto(tgetstr("cm", NULL), 0, 0));//, stdout);
		    ft_putstr("\e[1;1H\e[2J"); //clear
		    ft_putstr(tgoto(tgetstr("cm", NULL), 0, 0));//, stdout);
		    ft_putstr("TERMINAL TOO SMALL !!!");
		}
	    (*i)++;
	    (*j) = 2;
	}
    return (0);
}

int	ft_term_print_good_size(t_init **init, t_kernel **ker, short int *i, short int *j)
{
    if (ft_ck_size() == 0)
	{
	    if (ft_select_config_with_size(init, &(*ker)->ck) > 0)
		{
		    ft_select_print_out(&(*ker)->ck, &(*ker)->ctrl_z, init);
		}
	    (*i) = 2;
	    (*j) = 1;
	}
    else
	(*i) = 1;
    return (0);
}
