/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:05:43 by akolomoi          #+#    #+#             */
/*   Updated: 2018/10/28 15:05:44 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
{
	char	*s;
	size_t	i;

	if (str == NULL || f == NULL)
		return (NULL);
	s = ft_strnew(ft_strlen(str));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		s[i] = f(str[i]);
		i++;
	}
	s[i] = '\0';
	return (s);
}
