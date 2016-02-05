/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_config_free.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:57:54 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/01 15:56:04 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_select_config_liste.h"

int		ft_select_config_free(t_config_liste **t_c_l)
{

	if (*t_c_l == NULL)
	    return (0);
	free(*t_c_l);
	*t_c_l = NULL;
	return (1);
}
