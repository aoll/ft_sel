/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_tree_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 10:27:22 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/03 17:13:28 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_select_tree_col.h"
#include <time.h>

static void	ft_print_init_loop(const t_tree_col *t_t_c, const t_config_liste *t_c_l, t_env *e)
{
    e->x = t_t_c->x_curseur;
    e->tmp = t_c_l->i_nb_col_aff;
    e->j = 0;
    return;
}

static void	ft_print_call_tab_f(t_tree_col *t_t_c, const t_config_liste *t_c_l, void (**t)(const char *s, int _pa), t_env *e, int ck)
{
    if (t_t_c->ptr_tab[e->x]->s_name)
	t[t_t_c->ptr_tab[e->x]->si_etat]((const char*)t_t_c->ptr_tab[e->x]->s_name, t_c_l->i_l_str_max - (int)ft_strlen(t_t_c->ptr_tab[e->x]->s_name));
    if (ck == 1)
	e->ck = 1;
	return;
}

void		ft_select_tree_print(t_tree_col *t_t_c, const t_config_liste *t_c_l, void (**t)(const char *s, int _pa))
{
    t_env e;

    if (t_t_c->ptr_curseur == NULL || (e.ck = 0) != 0 || (e.i = 0) != 0)
	exit (0);
    while (e.i < t_c_l->i_nb_ligne_col)
	{
	    ft_print_init_loop((const t_tree_col*)t_t_c, t_c_l, &e); 
	    while (e.j < e.tmp && e.x < t_c_l->i_nb_col)
		{
		    if (t_t_c->ptr_tab[e.x]->si_end == 1)
			{
			    if (e.ck == 0)
				ft_print_call_tab_f(t_t_c, t_c_l, t, &e, 1);
			}
		    else
			{
			    ft_print_call_tab_f(t_t_c, t_c_l, t, &e, 0);
			    if (t_t_c->ptr_tab[e.x]->n)
				t_t_c->ptr_tab[e.x] = t_t_c->ptr_tab[e.x]->n;
			}
		    e.x = (++e.x > t_c_l->i_nb_col) ? 0 : e.x;
		    e.j++;
		}		  
	    (++e.i < t_c_l->i_nb_ligne_col) ? ft_putstr("\n") : 0;
	}
    return ;
}
