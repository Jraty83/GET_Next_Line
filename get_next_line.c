/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:00:35 by jraty             #+#    #+#             */
/*   Updated: 2020/08/11 23:21:23 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_get_line(char **s, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((*s)[i] && (*s)[i] != '\n')
		i++;
	if ((*s)[i] == '\0' || (*s)[i + 1] == '\0')
	{
		*line = ft_strsub(*s, 0, i);
		ft_strdel(s);
		return (1);
	}
	else if ((*s)[0] == '\n')
	{
		*line = ft_strnew(0);
		tmp = ft_strdup(*s + 1);
	}
	else
	{
		*line = ft_strsub(*s, 0, i);
		tmp = ft_strdup(*s + i + 1);
	}
	free(*s);
	*s = tmp;
	return (1);
}

static int	ft_return_value(int ret, char **s, char **line)
{
	if (ret == -1)
		return (-1);
	else if (*s == NULL)
		return (0);
	else
		return (ft_get_line(s, line));
}

int			get_next_line(const int fd, char **line)
{
	static char	*s[FD];
	char		*tmp;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(s[fd], '\n') != NULL)
			break ;
	}
	return (ft_return_value(ret, &s[fd], line));
}
