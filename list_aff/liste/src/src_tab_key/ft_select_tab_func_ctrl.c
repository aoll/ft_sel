/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_tab_func_ctrl.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:33:06 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/04 17:24:21 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_select_tab_key.h"

int	ft_select_key_return(t_config_liste **t_c_l, t_tree_col **t_t_c)
{
    ft_putstr("return\n");
    if (!*t_c_l || !*t_t_c)
	return (-1);
    exit (0);
    // ?? retourne un int particulier , a voir!
    return (0);
}

int	ft_select_key_space(t_config_liste **t_c_l, t_tree_col **t_t_c)
{
    t_liste *l;

    l = (*t_t_c)->ptr_curseur;
	if (!*t_c_l || !*t_t_c)
	    return (-1);
	if ((*t_t_c)->ptr_curseur->si_etat == 3)
	    (*t_t_c)->ptr_curseur->si_etat = 0;
	else
	    (*t_t_c)->ptr_curseur->si_etat = 1;
	//l->si_etat = 1;
	(*t_t_c)->ptr_curseur->n->si_etat = 2;
	(*t_t_c)->ptr_curseur = (*t_t_c)->ptr_curseur->n;
 
	if ((*t_t_c)->ptr_curseur->i_index_col >= (*t_t_c)->x_curseur + (*t_c_l)->i_nb_col_aff)
            (*t_t_c)->x_curseur = (*t_t_c)->x_curseur + (*t_c_l)->i_nb_col_aff;

        if ((*t_t_c)->ptr_curseur->si_start == 1)
            (*t_t_c)->x_curseur = 0;
        //(*t_t_c)->x_curseur++;                                                                                                               
        if ((*t_t_c)->x_curseur >= (*t_c_l)->i_nb_col)
            (*t_t_c)->x_curseur = 0;
	return (0);
}

int	ft_select_key_echap(t_config_liste **t_c_l, t_tree_col **t_t_c)
{
    if (!*t_c_l || !*t_t_c)
	return (-1);
    ft_putstr("ECHAP");
    exit(0); // doit retourner un int qui freera toutes les strucs/listes en cours!!
	return (0);
}

int	ft_select_key_sup_del(t_config_liste **t_c_l, t_tree_col **t_t_c)
{
    if (!*t_c_l || !*t_t_c)
	return (-1);
    ft_putstr("DEL");
    return (0);
}

