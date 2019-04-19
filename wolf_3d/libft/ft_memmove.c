/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:55:03 by akolomoi          #+#    #+#             */
/*   Updated: 2018/10/27 15:55:04 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ds;
	char	*sr;
	size_t	i;

	if (n == 0)
		return (dest);
	i = 0;
	ds = (char*)dest;
	sr = (char*)src;
	if (sr < ds)
	{
		while (n-- > 0)
			*(ds + n) = *(sr + n);
		*ds = *sr;
	}
	else
	{
		while (i < n)
		{
			*(ds + i) = *(sr + i);
			i++;
		}
	}
	return (dest);
}
