/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_read                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:39:54 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/04 18:33:05 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_select.h"

int	ft_select_buff_reset(char **buff, int *loop)
{
    if ((*buff))
	free ((*buff));
    (*buff) = NULL;
    (*buff) = ft_strnew(10000);
    (*loop) = 0;
    return (0);
}

int	ft_select_read(char **buff, t_init **init, t_kernel **ker)
{
    ft_tree_col_init_tab(&((*init)->t_t_c->ptr_tab), &(*init)->t_l, (*init)->t_c_l->i_nb_ligne_col, (*init)->t_c_l->i_nb_col);
    if (((*ker)->sup = (*init)->f[ft_select_table_0((*buff))][ft_select_table_1((*buff))][ft_select_table_2((*buff))](&(*init)->t_c_l, &(*init)->t_t_c)) == 0)
	(*ker)->ck++;
    ft_select_sup(&(*ker)->sup, &(*ker)->ck, init); // en fonction du retour break et free
    ft_select_buff_reset(buff, &(*ker)->loop);
    if ((*ker)->sup == 4 || (*ker)->sup == 5)
	return ((*ker)->sup);
    return (0);
}


int	ft_ck_size(void)
{
    struct winsize  size;

    if (ioctl(STDIN_FILENO,TIOCGWINSZ, (char*) &size) < 0)
	return (-1);
    if (size.ws_col < 25)
	//exit (0); // pa oublier de checker qu il y est au moins une ligne !!!!!
	return (1);
    return (0);
}
