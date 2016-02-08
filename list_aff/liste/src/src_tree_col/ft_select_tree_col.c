/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_tree_col.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 09:43:54 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/03 17:12:47 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_select_tree_col.h"

static void	ft_next_nb_col(t_liste **l, int i_nb_l_col, int index_col)
{
    int x;
//	t_liste *l;

//	l = *liste;
    //   printf("INDEX_COL ::%d\n", index_col);
    //exit (0);
    x = 0;
    while (x < i_nb_l_col)
	{
	    (*l)->i_index_col = index_col;
	    if ((*l)->si_end == 1)
		break;
	    (*l) = (*l)->n;
	    x++;
	}
    return ;
}

int	ft_tree_col_init_tab(t_liste ***ptr_tab, t_liste **liste, int i_nb_l_col, int i_nb_col)
{
    t_liste **tab;
    t_liste *l;
    int		x;

    
    tab = *ptr_tab;
    l = *liste;
    x = 0;
    while (x < i_nb_col)
	{
	    tab[x] = l;
	    ft_next_nb_col(&l, i_nb_l_col, x);
	    x++;
	}
    return (1);
}

int		ft_select_ptr_curseur(t_tree_col **t_t_c, t_liste **liste, const t_config_liste *t_c_l)
{
    t_liste *l;

    l = *liste;
    while (l)
    {
	if (l->si_etat == 2)
	    break;
	l = l->n;
    }
    (*t_t_c)->ptr_curseur = l;
    (*t_t_c)->x_curseur = l->i_index_col;
    if (l->i_index_col == t_c_l->i_nb_col - 1)
	(*t_t_c)->x_curseur = t_c_l->i_nb_col - t_c_l->i_nb_col_aff;
    return (0);
}

t_tree_col	*ft_select_tree_col_new(t_liste **liste, const t_config_liste *t_c_l)
{
    t_tree_col *n;
    //   t_liste *l;

    // l = *liste; ?? a la place de travailler directement sur ladresse
    if (!(n = malloc(sizeof(t_tree_col))))
		return (NULL);
    if (!(n->ptr_tab = malloc(sizeof(t_liste *) * (unsigned int)t_c_l->i_nb_col)))
		return (NULL);
	// n->ptr_tab[t_c_l->i_nb_col] = NULL;
    //	printf("nombre de collonne -->> %d\n", t_c_l->i_nb_col);
    
    ft_tree_col_init_tab(&n->ptr_tab, liste, t_c_l->i_nb_ligne_col, t_c_l->i_nb_col);
    ft_select_ptr_curseur(&n, liste, t_c_l);
    /*
    n->ptr_curseur = *liste; // a la place doit etre une fonction qui va parcourir la liste et savoir quel est letat 2 !!
    n->x_curseur = 0;
    */
    // printf("S_NAME%s, index_col%d\n", (*liste)->s_name, (*liste)->i_index_col); //debug
    //exit(0);
    return (n);
}
