/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:24:35 by akolomoi          #+#    #+#             */
/*   Updated: 2019/04/01 18:24:36 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include <libc.h>

int		create_window(t_game *window)
{
	int		tmp;


	tmp = 32;
	if (!(window->mlx = mlx_init()) ||
	!(window->win = mlx_new_window(window->mlx, W_WIDTH, W_HEIGHT,
	"Wolf3d by akolomoi")) ||
	!(window->img = mlx_new_image(window->mlx, W_WIDTH, W_HEIGHT)))
		return(0);
	return (1);
}
