/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:23:26 by akolomoi          #+#    #+#             */
/*   Updated: 2018/11/01 16:23:27 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*n;
	t_list	*k;

	n = *alst;
	while (n != NULL)
	{
		k = n->next;
		ft_lstdelone(&n, del);
		free(n);
		n = k;
	}
	*alst = NULL;
}
