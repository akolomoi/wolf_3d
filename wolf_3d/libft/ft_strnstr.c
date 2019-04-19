/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:34:26 by akolomoi          #+#    #+#             */
/*   Updated: 2018/10/27 19:34:28 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char*)haystack);
	i = 0;
	while (haystack[i] && i < n)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && i + j < n)
		{
			j++;
			if (j == ft_strlen(needle))
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
