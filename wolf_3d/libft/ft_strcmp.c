/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:56:12 by akolomoi          #+#    #+#             */
/*   Updated: 2018/10/25 20:56:13 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	size_t			s1_len;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	s1_len = 0;
	while (s1[s1_len])
	{
		if (s1[s1_len] != s2[s1_len])
			return (s1[s1_len] - s2[s1_len]);
		s1_len++;
	}
	if (s2[s1_len])
		return (-s2[s1_len]);
	return (0);
}
