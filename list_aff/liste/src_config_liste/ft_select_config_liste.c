/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_config_liste.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:57:54 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/03 09:09:41 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select_config_liste.h"

int					ft_length_str_liste_max(const t_liste *liste)
{
	int		i_length;
	int		i_tmp;

	if (liste == NULL)
		return (0);
	i_length = 0;
	while (liste)
	{
		if ((i_tmp = (int)ft_strlen(liste->s_name)) > i_length)
			i_length = i_tmp;
//		printf("S_NAME == %s, SI_start == %d, S_END == %d\n", liste->s_name, (int)liste->si_start, (int)liste->si_end);
		if (liste->si_end == 1)
		    break;
		liste = liste->n;
	}
	return (i_length + 5);
}

int					ft_nb_element_liste(const t_liste *liste)
{
	int	i_nb;

	if (liste == NULL)
		return (0);
	i_nb = 0;
	while (liste)
	{
		i_nb++;
		if (liste->si_end == 1)
		    break;
		liste = liste->n;
	}
	return (i_nb);
}

t_config_liste		*ft_select_config_liste_new(const t_liste *liste)
{
	t_config_liste	*n;
	struct winsize	size;
	
	if (ioctl(STDIN_FILENO,TIOCGWINSZ, (char*) &size) < 0)
		return (NULL);
	if (!(n = malloc(sizeof(t_config_liste))))
		return (NULL);
	n->si_y_term = (short int)size.ws_row;
	n->si_x_term = (short int)size.ws_col;
	n->i_l_str_max = ft_length_str_liste_max(liste);
	n->i_nb_liste = ft_nb_element_liste(liste);
	n->i_nb_col = 0;
	n->i_nb_ligne_col = 0;
	n->i_nb_col_aff = 0;
	n->i_index_col_aff = 0;
	return (n);
}
