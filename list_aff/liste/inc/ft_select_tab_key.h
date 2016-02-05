/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_tab_key.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 17:32:41 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/04 17:43:02 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_TAB_KEY_H
#define FT_SELECT_TAB_KEY_H

#include "../../../libft/libft.h"

typedef struct s_key	t_key;
struct	s_key
{
	int z;
	int y;
	int x;
};

int	ft_select_tab_key_new(int (* ****f)(void));

int    ft_select_table_0(t_key **key, char *s);
int    ft_select_table_1(t_key **key, char *s);
int    ft_select_table_2(t_key **key, char *s);

int     ft_select_key_up(void);
int     ft_select_key_down(void);
int     ft_select_key_right(void);
int     ft_select_key_left(void);

int     ft_select_key_return(void);
int     ft_select_key_space(void);
int     ft_select_key_echap(void);
int     ft_select_key_sup_del(void);

#endif
