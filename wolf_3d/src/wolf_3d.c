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

int		main(int ac, char **av)
{
	t_game	game;

	if (ac > 2)
		die(TOO_MANY_PARAMS);
	if (ac < 2)
		die(INVALID_PARAMS);
	if (!create_window(&game))
		die(MLX_FAILED);
	get_map(&game, av[1]);
	init_player(&game);
	load_textures(&game);
	draw_game(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.win, 17, 1L << 17, game_exit, &game);
	mlx_loop_hook(game.mlx, hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
