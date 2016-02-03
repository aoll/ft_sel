/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 22:42:27 by aollivie          #+#    #+#             */
/*   Updated: 2014/11/14 18:36:22 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dst2;

	dst2 = (unsigned char *)dst;
	if (dst < src)
	{
		while (len--)
		{
			*(unsigned char *)dst2 = *(unsigned char *)src;
			dst2++;
			src++;
		}
	}
	else if (dst == src)
		return (dst);
	else
	{
		while (len--)
		{
			*((unsigned char *)dst2 + len) = *((unsigned char *)src + len);
		}
	}
	return (dst);
}
