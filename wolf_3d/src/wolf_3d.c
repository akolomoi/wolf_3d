/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:26:51 by akolomoi          #+#    #+#             */
/*   Updated: 2019/03/26 17:26:52 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include <libc.h>

int		main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		die(INVALID_PARAMS);
	if (!create_window(&game.win))
		die(MLX_FAILED);	//creates window
	get_map(&game, av[1]);
	/*int i = -1;
	while (++i < MAP_SIZE)
	{
		printf("\n");
		int j = -1;
		while (++j < MAP_SIZE)
			printf("%d ", game.info.map[i][j]);
	}*/
	printf("\n");
	mlx_hook(game.win.win, 2, 1L << 0, game_keyboard , &game);
	mlx_hook(game.win.win, 17, 1L << 17, game_exit, &game);
	mlx_loop(game.win.mlx);
	return (0);
}
