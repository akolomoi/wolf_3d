/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:52:09 by akolomoi          #+#    #+#             */
/*   Updated: 2018/10/28 14:52:10 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *str, void (*f)(char*))
{
	size_t	i;

	if (str == NULL)
		return ;
	else if (f == NULL)
		return ;
	i = 0;
	while (str[i])
	{
		f(&str[i]);
		i++;
	}
}
