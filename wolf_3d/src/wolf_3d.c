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

static void pp(t_window *win, int x, int y, int c)
{
    *(int*)(win->img_adr + sizeof(int) * (x + y * W_WIDTH)) = c;
}

int		main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		die(INVALID_PARAMS);
	if (!create_window(&game.win))
		die(MLX_FAILED);
	get_map(&game, av[1]);
    init_player(&game);
    //draw_game(&game);
    int i = -1;
    int j;
    while (++i < W_HEIGHT && (j = -1))
        while (++j < W_WIDTH)
            pp(&game.win, j, i, i * (j * i));
            //mlx_pixel_put(game.win.mlx, game.win.win, j, i, i * (j * i));
    mlx_put_image_to_window(game.win.mlx,game.win.win, game.win.img, 0, 0);
	mlx_hook(game.win.win, 2, 1L << 0, game_keyboard , &game);
	mlx_hook(game.win.win, 17, 1L << 17, game_exit, &game);
	mlx_loop(game.win.mlx);
	return (0);
}
