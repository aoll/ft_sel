/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:08:04 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/04 17:09:38 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_select_tab_key.h"

int	ft_select_table_0(char *s)
{
    // printf("%d, %d, %d\n", s[0], s[1], s[2]);
    // exit(0);
    	if (s[0] == 27)
		return(1);
	else if (s[0] == 10)
		return(2);
	else if (s[0] == 32)
		return(3);
	else if (s[0] == 126)
		return(4);
	else if (s[0] == 127)
		return(5);
	else
		return(0);
}

int	ft_select_table_1(char *s)
{
	if (s[1] == 91)
		return (1);
	else if (s[1] == 0)
		return (2);
	else 
		return (0);
}

int	ft_select_table_2(char *s)
{
    	if (s[2] == 65)
		return (1);
	else if (s[2] == 66)
		return (2);
	else if (s[2] == 67)
		return (3);
	else if (s[2] == 68)
		return (4);
	else if (s[2] == 0)
		return (5);
	else if (s[2] == 51)
		return (6);
	else
		return (0);
}
