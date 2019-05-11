/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:15:16 by akolomoi          #+#    #+#             */
/*   Updated: 2019/04/10 17:15:17 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include "../includes/keys.h"
#include <libc.h>

int		game_keyboard(int k, t_game *game)
{
	if (k == KEY_ESC)
		game_exit(game);
    else if (k == KEY_LEFT)
    {
        game->player.dir -= M_PI / 60;
    }
    else if (k == KEY_RIGHT)
    {
        game->player.dir += M_PI / 60;
    }
    else if (k == KEY_UP)
    {
        game->player.pos_x += 0.15 * sin(game->player.dir);
        game->player.pos_x += 0.15 * cos(game->player.dir);
        if (game->map[(int)game->player.pos_x][(int)game->player.pos_y] && game->map[(int)game->player.pos_x][(int)game->player.pos_y] != 9)
        {
            game->player.pos_x -= 0.15 * sin(game->player.dir);
            game->player.pos_x -= 0.15 * cos(game->player.dir);
        }
    }
    else if (k == KEY_DOWN)
    {
        game->player.pos_x -= 0.15 * sin(game->player.dir);
        game->player.pos_x -= 0.15 * cos(game->player.dir);
        if (game->map[(int)game->player.pos_x][(int)game->player.pos_y] && game->map[(int)game->player.pos_x][(int)game->player.pos_y] != 9)
        {
            game->player.pos_x += 0.15 * sin(game->player.dir);
            game->player.pos_x += 0.15 * cos(game->player.dir);
        }
    }
	else if (k == KEY_SPACE)
	{
		int i = 0;printf("\nplayer[%d][%d]\n", game->player.spawn_x, game->player.spawn_y);
		game->map[game->player.spawn_x][game->player.spawn_y] = 9;
		while (i < MAP_SIZE)
		{
			
			printf("\n");
			int j = 0;
			while (j < MAP_SIZE)
				{printf("%d ", game->map[i][j]); j++;}
			i++;
		}
	printf("\n");
	}
	draw_game(game);
	return (1);
}

int		game_exit(t_game *param)
{
	param = (t_game*)param;
//	system("leaks -quiet wolf3d");

	exit(EXIT_SUCCESS);
	return (1);
}
