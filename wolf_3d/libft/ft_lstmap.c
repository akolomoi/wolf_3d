/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:37:55 by akolomoi          #+#    #+#             */
/*   Updated: 2018/11/01 16:37:56 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*cr;

	cr = (t_list*)malloc(sizeof(t_list));
	if (lst == NULL || f == NULL || cr == NULL)
		return (NULL);
	cr = f(lst);
	res = cr;
	while (lst->next != NULL)
	{
		lst = lst->next;
		cr->next = (t_list*)malloc(sizeof(t_list));
		if (cr->next == NULL)
			return (NULL);
		cr->next = f(lst);
		cr = cr->next;
	}
	return (res);
}
