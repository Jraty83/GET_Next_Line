/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:19:27 by jraty             #+#    #+#             */
/*   Updated: 2021/05/17 12:45:20 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	char	*ret;

	s2 = (char *)malloc(sizeof(*s1) * (n + 1));
	if (!s2)
		return (NULL);
	ret = s2;
	while (*s1 && n--)
		*s2++ = *s1++;
	*s2 = '\0';
	return (ret);
}
