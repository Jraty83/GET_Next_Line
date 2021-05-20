/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 11:46:47 by jraty             #+#    #+#             */
/*   Updated: 2021/05/20 21:00:04 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_count(int n)
{
	int		len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		++len;
	}
	if (n == 0)
	{
		++len;
	}
	while (n > 0)
	{
		n = n / 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	ln;

	len = ft_digit_count(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	ln = (long)n;
	if (ln < 0)
	{
		str[0] = '-';
		ln = -ln;
	}
	if (ln == 0)
		str[0] = '0';
	while (ln > 0)
	{
		str[len--] = ln % 10 + '0';
		ln = ln / 10;
	}
	return (str);
}
