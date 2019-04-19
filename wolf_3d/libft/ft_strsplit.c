/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:13:27 by akolomoi          #+#    #+#             */
/*   Updated: 2018/10/28 16:13:29 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		cnt(const char *str, char c)
{
	size_t	i;
	int		words;

	i = 0;
	words = 1;
	if (str[0] == c && str[0])
		words--;
	if (words)
		while (str[i] && str[i] != c)
			i++;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] && str[i + 1] != c)
			words++;
		i++;
	}
	if (str[i - 1] != c && str[i - 2] == c)
		words++;
	return (words);
}

static	size_t	len_of(const char *str, int ind, char del)
{
	size_t	l;

	l = 0;
	while (str[ind + l] && str[ind + l] != del)
		l++;
	return (l);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		w;
	int		i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	w = cnt(s, c);
	j = 0;
	res = (char**)malloc(sizeof(char*) * (w + 1));
	if (!res)
		return (NULL);
	res[w] = NULL;
	i = 0;
	while (i < w && s[j])
	{
		while (s[j] == c && s[j])
			j++;
		res[i] = ft_strsub(s, j, len_of(s, j, c));
		while (s[j] != c && s[j])
			j++;
		i++;
	}
	return (res);
}
