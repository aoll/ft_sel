/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_liste.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 18:39:45 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/01 10:05:28 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_select_liste.h"

static t_liste	*ft_liste_new(const char *s)
{
	t_liste *n;

	if (!(n = malloc(sizeof(t_liste))))
		return (NULL);
	n->i_length = (int)ft_strlen(s);
	n->si_etat = 0;
	n->si_start = 0;
	n->si_end = 0;
	n->s_name = ft_strdup(s);
	n->n = NULL;
	n->p = NULL;
	return (n);
}

static int		ft_liste_add(t_liste **liste, t_liste *n)
{
	t_liste *l;

	if (n == NULL)
		return (0);
	l = *liste;
	*liste = n;
	(*liste)->n = l;
	l->p = *liste;
	return (1);
}

static int		ft_liste(t_liste **liste, const char *s)
{
	if (*liste == NULL)
	{
		if ((*liste = ft_liste_new(s)) == NULL)
			return (0);
	}
	else if (!(ft_liste_add(liste, ft_liste_new(s))))
		return (0);
	return (1);
}

static int	ft_liste_link_start_end(t_liste **liste)
{
    t_liste *l;

    if (*liste == NULL)
	return (0);
    l = *liste;
    while (l->n)
	l = l->n;
    l->n = *liste;
    (*liste)->p = l;
    return (0);
}

t_liste			*ft_select_liste(const int ac, const char **tab)
{
	t_liste		*liste;
	int			i_x;

	liste = NULL;
	i_x = ac - 1;
	if (tab == NULL)
		return (NULL);
	while (i_x >= 0)
	{
		if (!ft_liste(&liste, tab[i_x]))
			return (NULL);
		if (i_x == 0)
		{
			liste->si_etat = 2;
			liste->si_start = 1;
		}
		if (i_x == (ac - 1))
		    liste->si_end = 1;
		i_x--;
	}
	ft_liste_link_start_end(&liste);
	return (liste);
}
