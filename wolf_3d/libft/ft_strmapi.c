/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:12:28 by akolomoi          #+#    #+#             */
/*   Updated: 2018/10/28 15:12:29 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char	*s;
	size_t	i;

	if (str == NULL || f == NULL)
		return (NULL);
	s = ft_strnew(ft_strlen(str));
	i = 0;
	if (s == NULL)
		return (NULL);
	while (str[i])
	{
		s[i] = f(i, str[i]);
		i++;
	}
	s[i] = '\0';
	return (s);
}
