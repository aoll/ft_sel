/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_config_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 12:05:47 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/01 15:55:18 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_select_config_liste.h"

int	ft_only_one_col(t_config_liste **t_c_l)
{
    t_config_liste *t;

    if (*t_c_l == NULL)
	return (0);
    t = *t_c_l;
    t->i_nb_col = 1;
    t->i_nb_ligne_col = t->i_nb_liste;
    t->i_nb_col_aff = 1;
    t->i_index_col_aff = 0;
    return (1);
}

int	ft_many_col(t_config_liste **t_c_l)
{
	t_config_liste	*t;

	if (*t_c_l == NULL)
	    return (0); 
	t = *t_c_l;
	t->i_nb_ligne_col = (int)t->si_y_term;
	t->i_nb_col = t->i_nb_liste / t->i_nb_ligne_col;
	((t->i_nb_liste % t->i_nb_ligne_col) > 0) ? t->i_nb_col++ : 0;
	if ((t->i_nb_col * t->i_l_str_max) <= (int)t->si_x_term)
	    t->i_nb_col_aff = t->i_nb_col;
	else
	    t->i_nb_col_aff = (int)t->si_x_term / t->i_l_str_max;
	t->i_index_col_aff = 0;	
	return (1);
}

int			ft_select_config_init(t_config_liste **t_c_l)//, const t_liste *liste)
{
	t_config_liste	*t;

	if (*t_c_l == NULL)
	    return (0); 
	t = *t_c_l;
	if (t->si_x_term < t->i_l_str_max)
		return (0);
	if (t->si_y_term >= t->i_nb_liste)
	    return (ft_only_one_col(t_c_l));
	else
	    return (ft_many_col(t_c_l));
	return (0);
}
