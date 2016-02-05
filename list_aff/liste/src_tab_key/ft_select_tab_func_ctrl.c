/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_tab_func_ctrl.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:33:06 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/04 17:24:21 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select_tab_key.h"

int	ft_select_key_return(void)
{
    ft_putstr("return\n");
	return (1);
}

int	ft_select_key_space(void)
{
	ft_putstr("SPACE\n");
	return (1);
}

int	ft_select_key_echap(void)
{
    ft_putstr("ECHAP");
	return (0);
}

int	ft_select_key_sup_del(void)
{
    ft_putstr("DEL");
	return (1);
}

