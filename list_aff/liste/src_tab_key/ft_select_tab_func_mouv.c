/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_tab_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:24:14 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/04 17:37:41 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select_tab_key.h"

int		ft_select_key_up(void)
{
	ft_putstr("UP");
	return (1);
}

int	ft_select_key_down(void)
{
	ft_putstr("DOWN");
	return (1);
}

int	ft_select_key_right(void)
{
	ft_putstr("rIGHT");
	return (1);
}

int	ft_select_key_left(void)
{
	ft_putstr("LEFT");
	return (1);
}
