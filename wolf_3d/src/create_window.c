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

int		create_window(t_game *window)
{
	if (!(window->mlx = mlx_init()) ||
	!(window->win = mlx_new_window(window->mlx, W_WIDTH, W_HEIGHT,
	"Wolf3d by akolomoi")) ||
	!(window->img = mlx_new_image(window->mlx, W_WIDTH, W_HEIGHT)))
		return (0);
	return (1);
}

int		set_spawn(t_game *game, int i, int j)
{
	while (++i < MAP_SIZE && (j = -1))
		while (++j < MAP_SIZE)
			if (game->map[i][j] == 0)
			{
				game->player.spawn_x = j;
				game->player.spawn_y = i;
				return (0);
			}
	return (1);
}
