/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:27:07 by akolomoi          #+#    #+#             */
/*   Updated: 2018/10/25 20:27:08 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char*)malloc(size * sizeof(*s) + 1);
	if (!s)
		return (NULL);
	while (i < size + 1)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
