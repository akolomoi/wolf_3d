/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:01:30 by akolomoi          #+#    #+#             */
/*   Updated: 2018/11/01 16:01:31 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t cs)
{
	t_list	*res;

	res = (t_list*)malloc(sizeof(*res));
	if (res == NULL)
		return (NULL);
	if (content == NULL)
	{
		res->content = NULL;
		res->content_size = 0;
	}
	else
	{
		res->content = malloc(cs);
		if (res->content == NULL)
			return (NULL);
		ft_memcpy(res->content, content, cs);
		res->content_size = cs;
	}
	res->next = NULL;
	return (res);
}
