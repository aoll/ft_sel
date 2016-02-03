/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_config_liste.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:45:24 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/01 12:12:47 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_CONFIG_LISTE_H
#define FT_SELECT_CONFIG_LISTE_H

#include "../../../libft/libft.h"
#include "ft_select_liste.h"
#include <sys/ioctl.h>
#include <termios.h>

typedef struct s_config_liste	t_config_liste;
struct	s_config_liste
{
	short int	si_y_term;
	short int	si_x_term;
	int			i_l_str_max;
	int			i_nb_liste;
	int			i_nb_ligne_col;
	int			i_nb_col;
	int			i_nb_col_aff;
	int			i_index_col_aff;
};

t_config_liste      *ft_select_config_liste_new(const t_liste *liste);

int					ft_select_config_init(t_config_liste **t_c_l);

int		    ft_select_config_free(t_config_liste **t_c_l);
#endif
