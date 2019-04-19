/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:20:35 by akolomoi          #+#    #+#             */
/*   Updated: 2018/10/27 15:20:36 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ds;
	char	*sr;

	sr = (char*)src;
	ds = dest;
	i = 0;
	while (i < n)
	{
		*(ds + i) = *(sr + i);
		i++;
	}
	return (dest);
}
