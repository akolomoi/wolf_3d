/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:53:19 by akolomoi          #+#    #+#             */
/*   Updated: 2018/10/28 15:53:20 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		is_ws(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static	int		full_blank(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!is_ws(str[i]))
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s)
{
	size_t	z;
	size_t	i;
	size_t	sz;
	char	*res;

	if (s == NULL)
		return (NULL);
	if (!full_blank(s))
		return (ft_strdup(""));
	i = 0;
	sz = ft_strlen(s);
	z = ft_strlen(s) - 1;
	while (is_ws(s[i]))
		i++;
	while (is_ws(s[z]))
		z--;
	res = (char*)malloc(sizeof(*res) * (sz - (sz - z + i) + 1));
	if (res == NULL)
		return (NULL);
	res = ft_strsub(s, i, (ft_strlen(s) - (sz - z + i) + 1));
	return (res);
}
