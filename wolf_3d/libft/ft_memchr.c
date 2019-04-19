/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 16:56:13 by akolomoi          #+#    #+#             */
/*   Updated: 2018/10/27 16:56:14 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t	i;
	char	*s;

	s = (char*)src;
	c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)*(s + i) == c)
			return (s + i);
		i++;
	}
	return (NULL);
}
