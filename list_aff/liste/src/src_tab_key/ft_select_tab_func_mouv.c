/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_tab_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:24:14 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/04 17:37:41 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_select_tab_key.h"

static void	ft_key_change_etat(t_tree_col **t_t_c)
{
	if ((*t_t_c)->ptr_curseur->si_etat == 3)
	    (*t_t_c)->ptr_curseur->si_etat = 1;
	else
	    (*t_t_c)->ptr_curseur->si_etat = 0;
	return;
}

int		ft_select_key_up(t_config_liste **t_c_l, t_tree_col **t_t_c)
{
    if (!*t_c_l || !*t_t_c)
	return (-1);

    ft_key_change_etat(t_t_c);

    (*t_t_c)->ptr_curseur = (*t_t_c)->ptr_curseur->p;
    if ((*t_t_c)->ptr_curseur->si_etat == 1)
	(*t_t_c)->ptr_curseur->si_etat = 3;
    else
	(*t_t_c)->ptr_curseur->si_etat = 2;
    //NIMPORTE QUOI !!!
   
    if ((*t_t_c)->ptr_curseur->si_end == 1)
    	(*t_t_c)->x_curseur = (*t_c_l)->i_nb_col - (*t_c_l)->i_nb_col_aff;
    else if ((*t_t_c)->ptr_curseur->i_index_col < (*t_t_c)->x_curseur)
	(*t_t_c)->x_curseur = (*t_t_c)->x_curseur - (*t_c_l)->i_nb_col_aff; // +1
    if ((*t_t_c)->x_curseur < 0)
	(*t_t_c)->x_curseur = 0;
    //if ((*t_t_c)->x_curseur >= (*t_c_l)->i_nb_col)
    //	(*t_t_c)->x_curseur = 0;
    return (0);
}

int	ft_select_key_down(t_config_liste **t_c_l, t_tree_col **t_t_c)
{
    //	ft_putstr("DOWN");
	if (!*t_c_l || !*t_t_c)
	    return (-1);
	//printf("INDEX :: %d\n", (*t_t_c)->ptr_curseur->i_index_col);//debug
	//exit(0);//debug

	ft_key_change_etat(t_t_c);
	(*t_t_c)->ptr_curseur = (*t_t_c)->ptr_curseur->n;
	if ((*t_t_c)->ptr_curseur->si_etat == 1)
	    (*t_t_c)->ptr_curseur->si_etat = 3;
	else
	    (*t_t_c)->ptr_curseur->si_etat = 2;
		
	if ((*t_t_c)->ptr_curseur->i_index_col >= (*t_t_c)->x_curseur + (*t_c_l)->i_nb_col_aff)
	    (*t_t_c)->x_curseur = (*t_t_c)->x_curseur + (*t_c_l)->i_nb_col_aff;
	
	if ((*t_t_c)->ptr_curseur->si_start == 1)
	    (*t_t_c)->x_curseur = 0;
	//(*t_t_c)->x_curseur++;
	if ((*t_t_c)->x_curseur >= (*t_c_l)->i_nb_col)
	    (*t_t_c)->x_curseur = 0;
	//return (0);
	return (0);
}

int	ft_select_key_right(t_config_liste **t_c_l, t_tree_col **t_t_c)
{
    int i;
    int x_col;
    int ck;
    
    i = 0;
    ck = 0;
    if (!*t_c_l || !*t_t_c)
	return (-1);
    if ((*t_c_l)->i_nb_col == 1)
	return (0);
    ft_key_change_etat(t_t_c);
    x_col = (*t_t_c)->ptr_curseur->i_index_col;
    
    if (x_col == (*t_c_l)->i_nb_col - 1)
	{  
	    while ((*t_t_c)->ptr_curseur->p->i_index_col == x_col)
		{
		    (*t_t_c)->ptr_curseur = (*t_t_c)->ptr_curseur->p;
		    i++;
		}
	    while ((*t_t_c)->ptr_curseur->i_index_col == (*t_c_l)->i_nb_col - 1)
		{
		    (*t_t_c)->ptr_curseur = (*t_t_c)->ptr_curseur->n;
		 
		}
	    while (i)
		{
		    (*t_t_c)->ptr_curseur = (*t_t_c)->ptr_curseur->n;
		    i--;
		}

	    	    (*t_t_c)->x_curseur = 0;
	}
    else
	{
	    i = 0;
	    while (i < (*t_c_l)->i_nb_ligne_col )
		{
		    if ((*t_t_c)->ptr_curseur->si_end == 1)
			break;
		(*t_t_c)->ptr_curseur = (*t_t_c)->ptr_curseur->n;
		i++;
		}
	}

    if ((*t_t_c)->ptr_curseur->si_etat == 1)
	(*t_t_c)->ptr_curseur->si_etat = 3;
    else
	(*t_t_c)->ptr_curseur->si_etat = 2;
  
    if ((*t_t_c)->ptr_curseur->i_index_col >= (*t_t_c)->x_curseur + (*t_c_l)->i_nb_col_aff)
	(*t_t_c)->x_curseur = (*t_t_c)->x_curseur + (*t_c_l)->i_nb_col_aff;
    
    //    if ((*t_t_c)->ptr_curseur->si_start == 1)
    //
    //(*t_t_c)->x_curseur++;
    if ((*t_t_c)->x_curseur >= (*t_c_l)->i_nb_col)
	(*t_t_c)->x_curseur = 0;

    return (0);
	
}

int	ft_select_key_left(t_config_liste **t_c_l, t_tree_col **t_t_c)
{
    if (!*t_c_l || !*t_t_c)
	return (-1);
    if ((*t_c_l)->i_nb_col == 1)
	return (0);
    ft_key_change_etat(t_t_c);
    return (0);
}
