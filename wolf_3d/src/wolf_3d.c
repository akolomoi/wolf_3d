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
/*
static void pp(t_game *game, int x, int y, int c)
{
    int i = 32;
    game->img_adr = mlx_get_data_addr(game->img, &i,&i,&i);
    //printf("pp\nmlx:    %p\nwin:    %p\nimg    %p\nimgadr %p\n", game->mlx, game->win, game->img, game->img_adr);
    *(int*)(game->img_adr + sizeof(int) * (x + y * W_WIDTH)) = c;
}
*/
int		main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		die(INVALID_PARAMS);
	if (!create_window(&game))
		die(MLX_FAILED);
	get_map(&game, av[1]);
   // printf("main\nmlx:    %p\nwin:    %p\nimg    %p\nimgadr %p\n", game.mlx, game.win, game.img, game.img_adr);
    init_player(&game);
    draw_game(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
    mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.win, 17, 1L << 17, game_exit, &game);
	mlx_loop_hook(game.mlx, hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
