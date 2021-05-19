/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:02:28 by jraty             #+#    #+#             */
/*   Updated: 2021/05/17 12:46:03 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*ret;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(*str) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	ret = str;
	while (*s)
		*str++ = f(i++, *s++);
	*str = '\0';
	return (ret);
}
