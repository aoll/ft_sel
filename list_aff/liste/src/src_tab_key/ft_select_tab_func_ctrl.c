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
    return (0);
}

int	ft_select_key_space(t_config_liste **t_c_l, t_tree_col **t_t_c)
{
	ft_putstr("SPACE\n");
	if (!*t_c_l || !*t_t_c)
	    return (-1);
	return (0);
}

int	ft_select_key_echap(t_config_liste **t_c_l, t_tree_col **t_t_c)
{
    if (!*t_c_l || !*t_t_c)
	return (-1);
    ft_putstr("ECHAP");
    exit(0); // doit retourner un int qui freera toutes les strucs/listes en cours!!
	return (0);
}

int	ft_select_key_sup_del(t_config_liste **t_c_l, t_tree_col **t_t_c)
{
    if (!*t_c_l || !*t_t_c)
	return (-1);
    ft_putstr("DEL");
    return (0);
}

