/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:47:51 by akolomoi          #+#    #+#             */
/*   Updated: 2018/10/26 16:47:54 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*k;
	void	*start;

	i = 0;
	k = s;
	start = s;
	while (i < n)
	{
		*(k + i) = c;
		i++;
	}
	return (start);
}
