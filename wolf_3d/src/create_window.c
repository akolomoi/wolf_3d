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

void	start_game(t_game *game)
{
	mlx_hook(game->win.win, 2, 1L << 0, game_keyboard , &game);
	mlx_hook(game->win.win, 17, 1L << 17, game_exit, &game);
	mlx_loop(game->win.mlx);
}

int		create_window(t_window	*window)
{
	int		tmp;


	tmp = 32;
	if (!(window->mlx = mlx_init()) ||
	!(window->win = mlx_new_window(window->mlx, W_WIDTH, W_HEIGHT,
	"Wolf3d by akolomoi")) ||
	!(window->img = mlx_new_image(window->mlx, W_WIDTH, W_HEIGHT)) ||
	!(window->img_adr = mlx_get_data_addr(window->img, &tmp, &tmp, &tmp)))
		return(0);
	return (1);
}
