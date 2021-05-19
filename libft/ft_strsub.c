/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:34:04 by jraty             #+#    #+#             */
/*   Updated: 2021/05/17 12:41:11 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	i = 0;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!(s && sub))
		return (NULL);
	while (s[start] && len--)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
