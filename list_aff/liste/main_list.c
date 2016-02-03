/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:39:54 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/03 17:49:28 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_select_liste.h"
#include "inc/ft_select_config_liste.h"
#include "inc/ft_select_tree_col.h"
#include "inc/ft_select_tab_key.h"

void	ft_p_t_c(t_config_liste *t)
{
	printf("y_term = %d,  x_term = %d, str_max = %d, i_nb_l = %d, i_nb_col = %d, i_nb_coll_aff = %d, i_index_coll_a_aff = %d\n", t->si_y_term ,  t->si_x_term ,  t->i_l_str_max ,  t->i_nb_ligne_col ,  t->i_nb_col , t->i_nb_col_aff, t->i_index_col_aff);
	return ;
}

int	main(int ac, char **av)
{
	t_liste			*l;
	t_config_liste	*c_l;
	t_tree_col	*t_t_c;
	void	(**t)(const char *, int _pa);
	void	(****f);

	if ((l = ft_select_liste((const int)(ac - 1),\
						(const char **)(++av))) == NULL)
		return (0);
	if ((c_l = ft_select_config_liste_new((const t_liste*)(l))) == NULL)
	    return (0);
	if (!ft_select_config_init(&c_l))
		ft_putstr("Error: terminal to small\n");
	ft_p_t_c(c_l); // print verif
	t_t_c = ft_select_tree_col_new(&l, (const t_config_liste*)c_l);
	ft_select_tree_tab_f(&t);
	ft_select_tree_print((const t_liste**)t_t_c->ptr_tab, (const t_config_liste*)c_l, t);
  
	f = ft_select_tab_key();

	ft_select_liste_free(&l); // return 0 si pas alloue
	ft_select_config_free(&c_l); // return 0 si pas alloue
	ft_select_tree_free(&t_t_c); // return 0 si pas alloue
	ft_select_tree_tab_f_free(&t); // return 0 si pas alloue
//	printf("align %zu\n", sizeof(t_liste));
//	ft_putstr("HELLO\n");
	return (0);
}
