/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:47:52 by akolomoi          #+#    #+#             */
/*   Updated: 2018/10/25 20:47:54 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		size;
	int		i;
	char	*res;

	size = 0;
	i = 0;
	size = ft_strlen(s);
	if ((res = (char *)malloc(sizeof(*res) * (size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
