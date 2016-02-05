/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_liste_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 19:49:41 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/03 09:25:17 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_select_liste.h"

static void	ft_liste_free_prev(t_liste **liste)
{
	t_liste *l;

	l = *liste;
	if (l->p != NULL)
	{
		if (l->p->s_name != NULL)
			free(l->p->s_name);
		l->p->s_name = NULL;
		free(l->p);
		l->p = NULL;
	}
	return ;
}

int			ft_select_liste_free(t_liste **liste)
{
	t_liste *l;

	if (liste == NULL || (l = *liste) == NULL)
		return (0);
	if (l->si_start == 1 && l->si_end == 1)
	{
		if (l->s_name != NULL)
		    free(l->s_name);
		l->s_name = NULL;
		free(l);
		l = NULL;
		return (1);
	}
	if (l->p)
	    if (l->p->n != NULL)
		l->p->n = NULL;
	while (l->n)
	{
		ft_liste_free_prev(&l);
		l = l->n;
	}
	if (l->p != NULL)
		ft_liste_free_prev(&l);
/*
	if (l->s_name != NULL)
		free(l->s_name);
	l->s_name = NULL;
*/
/*
	free(l);
	l = NULL;
*/
	return (1);
}
