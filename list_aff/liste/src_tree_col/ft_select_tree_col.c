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

#include "../inc/ft_select_tree_col.h"

static void	ft_next_nb_col(t_liste **l, int i_nb_l_col)
{
    int x;
//	t_liste *l;

//	l = *liste;
    x = 0;
    while (x < i_nb_l_col)
	{
	    (*l) = (*l)->n;
	    x++;
	}
    return ;
}

static int	ft_tree_col_init_tab(t_liste ***ptr_tab, t_liste **liste, int i_nb_l_col, int i_nb_col)
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
	    ft_next_nb_col(&l, i_nb_l_col);
	    x++;
	}
    return (1);
}

t_tree_col	*ft_select_tree_col_new(t_liste **liste, const t_config_liste *t_c_l)
{
    t_tree_col *n;

    if (!(n = malloc(sizeof(t_tree_col))))
		return (NULL);
    if (!(n->ptr_tab = malloc(sizeof(t_liste *) * (unsigned int)t_c_l->i_nb_col)))
		return (NULL);
	// n->ptr_tab[t_c_l->i_nb_col] = NULL;
	printf("nombre de collonne -->> %d\n", t_c_l->i_nb_col);
    ft_tree_col_init_tab(&n->ptr_tab, liste, t_c_l->i_nb_ligne_col, t_c_l->i_nb_col);
    n->ptr_curseur = *liste;
    return (n);
}
