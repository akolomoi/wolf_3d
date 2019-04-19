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
	if (k == KEY_SPACE)
	{
		int i = 0;printf("\nplayer[%d][%d]\n", game->player.spawn_x, game->player.spawn_y);
		game->info.map[game->player.spawn_x][game->player.spawn_y] = 9;
		while (i < MAP_SIZE)
		{
			
			printf("\n");
			int j = 0;
			while (j < MAP_SIZE)
				{printf("%d ", game->info.map[i][j]); j++;}
			i++;
		}
	printf("\n");
	}
	return (1);
}

int		game_exit(t_game *param)
{
	param = (t_game*)param;
//	system("leaks -quiet wolf3d");

	exit(EXIT_SUCCESS);
	return (1);
}
