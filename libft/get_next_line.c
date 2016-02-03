/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 15:05:03 by aollivie          #+#    #+#             */
/*   Updated: 2015/02/02 14:36:48 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_mycpy(char **stat, char **line)
{
	size_t	i;
	size_t	l;
	char	*tp;

	tp = ft_strdup(*stat);
	i = 0;
	l = ft_strlen(tp);
	if (*stat[0] == '\n' || *stat[0] == '\0')
	{
		*line = ft_strnew(0);
		*stat = ft_strsub((char *)tp, 1, l - 1);
		free(tp);
		return (1);
	}
	while (tp[i] != '\n' && tp[i] != '\0')
		i++;
	if (tp[i] == '\n')
	{
		*stat = ft_strnew(0);
		*line = ft_strsub((char *)tp, 0, i);
		*stat = ft_strsub((char *)tp, i + 1, l - i - 1);
		free(tp);
		return (1);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	char		*buf;
	static char *stat;
	int			rd;

	*line = ft_strnew(0);
	buf = ft_strnew(BUFF_SIZE);
	if (fd < 0)
		return (-1);
	if (stat && (rd = ft_mycpy(&stat, line)) > 0)
		return (1);
	while ((rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		stat = ft_strjoin((const char *)stat, (const char *)buf);
		if ((rd = ft_mycpy(&stat, line)) > 0)
			return (1);
	}
	if (stat)
	{
		*line = ft_strdup(stat);
		stat = NULL;
		return (1);
	}
	*line = NULL;
	return (0);
}
