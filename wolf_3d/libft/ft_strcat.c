/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:12:53 by akolomoi          #+#    #+#             */
/*   Updated: 2018/10/27 19:12:55 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *temp;

	temp = dest;
	while (*temp)
		temp++;
	while (*src)
		*temp++ = *src++;
	*temp = '\0';
	return (dest);
}
