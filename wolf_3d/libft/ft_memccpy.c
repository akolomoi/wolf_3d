/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:30:03 by akolomoi          #+#    #+#             */
/*   Updated: 2018/10/27 15:30:04 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ds;

	i = 0;
	ds = (unsigned char*)dest;
	while (i < n)
	{
		*(ds + i) = *((unsigned char*)src + i);
		if (*(ds + i) == (unsigned char)c)
			return (ds + i + 1);
		i++;
	}
	return (NULL);
}
