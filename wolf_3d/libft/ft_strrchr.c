/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 22:08:15 by akolomoi          #+#    #+#             */
/*   Updated: 2018/10/25 22:08:18 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	size_t	i;

	i = 0;
	res = NULL;
	while (s[i])
	{
		if (s[i] == c)
			res = (char*)&s[i];
		i++;
	}
	if (c == '\0')
		res = (char*)&s[i];
	return (res);
}
