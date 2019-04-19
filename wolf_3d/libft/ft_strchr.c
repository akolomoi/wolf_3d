/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 21:46:16 by akolomoi          #+#    #+#             */
/*   Updated: 2018/10/25 21:46:17 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*res;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			res = (char*)&s[i];
			return (res);
		}
		i++;
	}
	if (c == '\0')
	{
		res = (char*)&s[i];
		return (res);
	}
	return (NULL);
}
