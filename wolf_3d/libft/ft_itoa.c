/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:16:20 by akolomoi          #+#    #+#             */
/*   Updated: 2018/10/28 16:16:21 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	l_of(int a)
{
	int		i;

	i = 0;
	if (a < 0)
		i++;
	while (a / 10)
	{
		i++;
		a = a / 10;
	}
	i++;
	return (i);
}

static char	*rev(char *str, int len)
{
	int		i;
	char	*res;
	int		j;

	i = 0;
	j = len - 1;
	res = ft_strnew(len);
	if (str[i] == '-')
	{
		res[i] = '-';
		i++;
	}
	while (str[i])
	{
		if (str[j] != '-')
			res[i] = str[j];
		j--;
		i++;
	}
	return (res);
}

char		*ft_itoa(int a)
{
	int		n;
	int		i;
	char	*res;

	if (a == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	n = l_of(a);
	res = ft_strnew(n);
	if (res == NULL)
		return (NULL);
	if (a < 0)
	{
		a = -a;
		res[0] = '-';
		i++;
	}
	while (a / 10)
	{
		res[i] = a % 10 + '0';
		a = a / 10;
		i++;
	}
	res[i] = a + '0';
	return (rev(res, n));
}
