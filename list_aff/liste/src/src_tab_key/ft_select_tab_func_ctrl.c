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
    ft_putstr("\033[?1049l"); //recharge le svg du terminal
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
	if (l->si_start == 1 && l->si_end == 1)
	    {
		if (l->si_etat == 3)
		    l->si_etat = 2;
		else
		    l->si_etat = 3;
		return (0);
	    }
	if ((*t_t_c)->ptr_curseur->si_etat == 3)
	    (*t_t_c)->ptr_curseur->si_etat = 0;
	else
	    (*t_t_c)->ptr_curseur->si_etat = 1;
	//l->si_etat = 1;
	if ((*t_t_c)->ptr_curseur->n->si_etat == 1)
	    (*t_t_c)->ptr_curseur->n->si_etat = 3;
	else
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
    // ft_putstr("\e[5;0H");
    ft_putstr("\033[?1049l"); //recharge le svg du terminal
    exit(0); // doit retourner un int qui freera toutes les strucs/listes en cours!!
	return (0);
}

int	ft_select_key_sup_del(t_config_liste **t_c_l, t_tree_col **t_t_c)
{
    t_liste *l = (*t_t_c)->ptr_curseur;
    t_liste *tmp_n = (*t_t_c)->ptr_curseur->n;
    t_liste *tmp_p = (*t_t_c)->ptr_curseur->p;
    int start = 0;
    int end = 0;

 
    /*
    (*t_t_c)->ptr_curseur = (*t_t_c)->ptr_curseur->n;
    (*t_t_c)->ptr_curseur->p->p->n = (*t_t_c)->ptr_curseur;
    (*t_t_c)->ptr_curseur->p = (*t_t_c)->ptr_curseur->p->p;
    return (0);
    */
    if (!*t_c_l || !*t_t_c)
	return (-1);
    
    if (l->si_start == 1 && l->si_end == 1)
	ft_select_key_echap(t_c_l, t_t_c);
  
    if (l->si_start == 1 )
	return (3);
	//l->n->si_start = 1;
    if (l->si_end == 1 )
	(*t_t_c)->ptr_curseur->p->si_end = 1;

    l->p = NULL;
    l->n = NULL;
    free(l->s_name);
    l->s_name = NULL;
    free(l);   // il faut "frire linterieur" !!
    l = NULL;
    
    tmp_n->p = tmp_p;
    tmp_p->n = tmp_n;
    (*t_t_c)->ptr_curseur = tmp_n;
    if ((*t_t_c)->ptr_curseur->si_etat == 1)
	(*t_t_c)->ptr_curseur->si_etat = 3;
    else
	(*t_t_c)->ptr_curseur->si_etat = 2;
    // exit (0);
    //    if (start)
    //	(*t_t_c)->ptr_curseur->si_start = 1
    	
    /*
    printf("%s\n\n", "----------------------end");
    printf("CU->p ::%s\n", (*t_t_c)->ptr_curseur->p->s_name);
    printf("CU ::%s\n", (*t_t_c)->ptr_curseur->s_name);
    printf("CU->n ::%s\n", (*t_t_c)->ptr_curseur->n->s_name);
    */
    //exit(0);
	/*
    if ((*t_t_c)->ptr_curseur->i_index_col >= (*t_t_c)->x_curseur + (*t_c_l)->i_nb_col_aff)
	(*t_t_c)->x_curseur = (*t_t_c)->x_curseur + (*t_c_l)->i_nb_col_aff;

    if ((*t_t_c)->ptr_curseur->si_start == 1)
	(*t_t_c)->x_curseur = 0;
    //(*t_t_c)->x_curseur++;                                                                                                               
    if ((*t_t_c)->x_curseur >= (*t_c_l)->i_nb_col)
	(*t_t_c)->x_curseur = 0;
    */
   
  
    return (2);
}

