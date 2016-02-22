/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_init.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:37:44 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/01 10:06:45 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_INIT_H
#define FT_SELECT_INIT_H

#include "../../../libft/libft.h"
#include "ft_select.h"

int     ft_select_ck_size_screen(t_config_liste **t_c_l);
int     ft_select_terminal_init(struct termios *terminal);
int     ft_select_struct_init(t_init **init, const int ac, const char **av);
int     ft_select_config_with_size(t_init **init, int *ck);
int     ft_select_init(t_init **init, t_kernel **ker, const int ac, const char **av);

#endif
