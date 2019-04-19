/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:45:48 by akolomoi          #+#    #+#             */
/*   Updated: 2018/11/18 17:33:37 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	if ((res = (char *)malloc(sizeof(char) * (ft_strlen(s1)
	+ ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	res = ft_strcpy(res, s1);
	res = ft_strcat(res, s2);
	free((void*)s1);
	return (res);
}
