/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_tree_tab_f.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 12:12:38 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/03 17:35:52 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/ft_select_tree_col.h"

int	ft_select_tree_tab_f_free(void (***t)(const char *s, int _pa))
{
//	int x;	x = 0;
	if (*t == NULL)
		return (0);
	free(*t);
	t = NULL;
/*
	while ((*t)[x])
	{
		free((*t)[x]);
		(*t)[x] = NULL;
		x++;
	}
*/
	return (1);
}
