/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_liste.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:37:44 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/01 10:06:45 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_LISTE_H
#define FT_SELECT_LISTE_H

#include "../../../libft/libft.h"

typedef struct s_liste	t_liste;
struct	s_liste
{
    int i_index_col;
    int			i_length;
    short int	si_etat;
    short int	si_start;
    short int	si_end;
    char	_pa[2];
	char		*s_name;
	t_liste		*n;
	t_liste		*p;
};

t_liste		*ft_select_liste(const int ac, const char **tab);
int			ft_select_liste_free(t_liste **liste);

#endif
