/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:58:31 by akolomoi          #+#    #+#             */
/*   Updated: 2018/10/28 14:58:33 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (str == NULL)
		return ;
	else if (f == NULL)
		return ;
	i = 0;
	while (str[i])
	{
		f(i, &str[i]);
		i++;
	}
}
