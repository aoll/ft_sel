/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_tree_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 09:27:34 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/03 10:26:29 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select_tree_col.h"
#include "../inc/ft_select_liste.h"

int		ft_select_tree_free(t_tree_col **t_t_col)
{
    t_tree_col *ptr_tmp;

	if (*t_t_col == NULL)
		return (0);
	ptr_tmp = *t_t_col;
	if (ptr_tmp->ptr_tab != NULL)
	{
		free(ptr_tmp->ptr_tab);
		ptr_tmp->ptr_tab = NULL;
	}
	free(ptr_tmp);
	ptr_tmp = NULL;
   return (1);
}
