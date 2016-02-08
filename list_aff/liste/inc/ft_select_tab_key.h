/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_tab_key.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 17:32:41 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/04 17:43:02 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_TAB_KEY_H
#define FT_SELECT_TAB_KEY_H

#include "../../../libft/libft.h"
#include "ft_select_config_liste.h"
#include "ft_select_tree_col.h"
/*
typedef struct s_key	t_key;
struct	s_key
{
	int z;
	int y;
	int x;
};
*/
int	ft_select_tab_key_new(int (* ****f)(t_config_liste **t_c_l, t_tree_col **t_t_c));

int    ft_select_table_0(char *s);
int    ft_select_table_1(char *s);
int    ft_select_table_2(char *s);

int     ft_select_key_up(t_config_liste **t_c_l, t_tree_col **t_t_c);
int     ft_select_key_down(t_config_liste **t_c_l, t_tree_col **t_t_c);
int     ft_select_key_right(t_config_liste **t_c_l, t_tree_col **t_t_c);
int     ft_select_key_left(t_config_liste **t_c_l, t_tree_col **t_t_c);

int     ft_select_key_return(t_config_liste **t_c_l, t_tree_col **t_t_c);
int     ft_select_key_space(t_config_liste **t_c_l, t_tree_col **t_t_c);
int     ft_select_key_echap(t_config_liste **t_c_l, t_tree_col **t_t_c);
int     ft_select_key_sup_del(t_config_liste **t_c_l, t_tree_col **t_t_c);

#endif
