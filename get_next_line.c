/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:00:35 by jraty             #+#    #+#             */
/*   Updated: 2020/08/04 16:41:26 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

void	ft_get_line(char **s, char **line)
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
	}
	else if ((*s)[0] != '\n')
	{
		(*s)[i] = '\0';
		*line = ft_strdup(*s);
		tmp = ft_strdup(*s + i + 1);
		free(*s);
		*s = tmp;
	}
	else
	{
		*line = ft_strnew(0);
		tmp = ft_strdup(*s + 1);
		free(*s);
		*s = tmp;
	}
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[66];
	char		*tmp;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(s[fd], buf);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n') != NULL)
			break ;
	}
	if (ret == -1)
		return (-1);
	if (s[fd] == NULL)
		return (0);
	ft_get_line(&s[fd], line);
	while (s[fd])
		return (1);
	return (s[fd] == NULL && *line ? 1 : 0);
}
