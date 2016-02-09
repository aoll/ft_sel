/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_config_liste.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:45:24 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/03 17:37:15 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_TREE_COL_H
#define FT_SELECT_TREE_COL_H

#include "../../../libft/libft.h"
#include "ft_select_config_liste.h"
#include <sys/ioctl.h>
#include <termios.h>


typedef struct s_tree_col	t_tree_col;
struct	s_tree_col
{
    t_liste **ptr_tab;
    t_liste *ptr_curseur;
    int x_curseur;
    char _pa[4];
};

typedef struct s_env t_env;
struct s_env
{
    int ck;
    int i;
    int x;
    int tmp;
    int j;
    char _pa[4];
};

t_tree_col      *ft_select_tree_col_new(t_liste **liste, const t_config_liste *t_c_l);
int     ft_tree_col_init_tab(t_liste ***ptr_tab, t_liste **liste, int i_nb_l_col, int i_nb_col);

void		ft_select_tree_print(t_tree_col *t_t_c, const t_config_liste *t_c_l, void (**t)(const char *s, int _pa));

void	ft_select_tree_tab_f(void (***t)(const char *s, int _pa));

int    ft_select_tree_tab_f_free(void (***t)(const char *s, int _pa));

int		    ft_select_tree_free(t_tree_col **t_tree_col);

#endif
