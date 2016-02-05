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

#include "../inc/ft_select_tab_key.h"

int	ft_select_table_0(t_key **key, char *s)
{
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
    /*
	if (s[0] == 27)
		(*key)->z = 1;
	else if (s[0] == 10)
		(*key)->z = 2;
	else if (s[0] == 32)
		(*key)->z = 3;
	else if (s[0] == 126)
		(*key)->z = 4;
	else if (s[0] == 127)
		(*key)->z = 5;
	else
		(*key)->z = 0;
    */
}

int	ft_select_table_1(t_key **key, char *s)
{
	if (s[1] == 91)
		return (1);
	else if (s[1] == 0)
		return (2);
	else 
		return (0);
	/*
	  	if (s[1] == 91)
		(*key)->y = 1;
	else if (s[1] == 0)
		(*key)->y = 2;
	else 
		(*key)->y = 0;
	*/
	
}

int	ft_select_table_2(t_key **key, char *s)
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
    /*
	if (s[2] == 65)
		(*key)->x = 1;
	else if (s[2] == 66)
		(*key)->x = 2;
	else if (s[2] == 67)
		(*key)->x = 3;
	else if (s[2] == 68)
		(*key)->x = 4;
	else if (s[2] == 0)
		(*key)->x = 5;
	else if (s[2] == 51)
		(*key)->x = 6;
	else
		(*key)->x = 0;
    */
}
