/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:39:54 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/04 18:33:05 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_select.h"

int	ft_select_free_liste_0(t_liste **t_l)
{
    t_liste *tmp;
    t_liste *l;

    l = *t_l;
    tmp = l;
    l = l->n;
    l->p->p->n = l;
    l->p = l->p->p;
    l->si_start = 1;
    if (l->si_etat == 1)
	l->si_etat = 3;
    else
	l->si_etat = 2;
    free(tmp->s_name);
    tmp->s_name = NULL;
    free (tmp);
    tmp = NULL; // doit etre free de linterieur !!
    *t_l = l;
    return (0);
}

int	ft_select_init_free(t_init **init)
{
    ft_select_liste_free(&(*init)->t_l); // return 0 si pas alloue
    ft_select_config_free(&(*init)->t_c_l); // return 0 si pas alloue
    ft_select_tree_free(&(*init)->t_t_c); // return 0 si pas alloue
    ft_select_tree_tab_f_free(&(*init)->t); // return 0 si pas alloue
    ft_select_tab_key_free(&(*init)->f);

    //    free(init); //??
    //init = NULL;
	return (0);
}

int     ft_select_out(t_liste *t_l)
{
    int i;

    i = 0;
    while (t_l)
        {
            if (t_l->si_etat == 1 || t_l->si_etat == 3)
                {
                    if(i > 0)
                        ft_putchar(' ');
                }
            if (t_l->si_etat == 1 || t_l->si_etat == 3)
                {
                    i++;
                    ft_putstr(t_l->s_name);
                }
            if (t_l->si_end == 1)
                break ;
            t_l = t_l->n;
        }
    return (0);
}

int	ft_select_end(t_init **init, t_kernel **ker, char **buff)
{
    ft_restore_term(0); // version sans le ctrl-Z
    if ((*ker)->key == 5)
	ft_select_out((*init)->t_l);
    ft_select_init_free(init);
    
    return (0);
}

int     ft_select_sup(int *sup, int *ck, t_init **init)
{
    int i;

    i = 0;
    if ((*sup) == 2 || (*sup) == 3)
	{
	    if ((*sup) == 3) // pourrait se faire avec une fonction qui prend (*sup) et ladresse de liste en parametre, retourne (*sup) , mais ava   nt si (*sup) == 3 (*sup) liste.0                                                                                                       
		{
		    ft_select_free_liste_0(&(*init)->t_l);
		}
	    if (((*init)->t_c_l = ft_select_config_liste_new((const t_liste*)((*init)->t_l))) == NULL)
		return (-1);
	    if (ft_select_config_init(&(*init)->t_c_l) < 0)
		{
		    if (!i)
			{
			    ft_putstr("\e[1;1H\e[2J"); //clear                                                                                         
			    ft_putstr("Error: terminal to small\n");
			    return (-1);
			}
		    i++;
		    //return (-1);                                                                                                                     
		}
	    (*ck)++;
	    ft_select_tree_free(&(*init)->t_t_c); // return 0 si pas alloue                                                                        
	    if (!((*init)->t_t_c = ft_select_tree_col_new(&(*init)->t_l, (const t_config_liste*)(*init)->t_c_l)))
		return (-1);
	}
    return (0);
}
