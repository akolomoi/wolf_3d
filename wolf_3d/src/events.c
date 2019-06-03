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

int			key_press(int k, t_game *game)
{
	if (k == KEY_UP || k == KEY_W)
		game->status.move_forwards = 1;
	else if (k == KEY_DOWN || k == KEY_S)
		game->status.move_backwards = 1;
	else if (k == KEY_LEFT || k == KEY_A)
		game->status.rotate_left = 1;
	else if (k == KEY_RIGHT || k == KEY_D)
		game->status.rotate_right = 1;
	else if (k == KEY_LSHIFT)
		game->player.speed = 0.17;
	else if (k == KEY_ESC)
		game_exit(game);
	return (0);
}

int			key_release(int k, t_game *game)
{
	if (k == KEY_UP || k == KEY_W)
		game->status.move_forwards = 0;
	else if (k == KEY_DOWN || k == KEY_S)
		game->status.move_backwards = 0;
	else if (k == KEY_LEFT || k == KEY_A)
		game->status.rotate_left = 0;
	else if (k == KEY_RIGHT || k == KEY_D)
		game->status.rotate_right = 0;
	else if (k == KEY_E)
		game->player.mode = (game->player.mode + 1) % M_TOTAL;
	else if (k == KEY_LSHIFT)
		game->player.speed = 0.1;
	return (0);
}

static void	rotate(t_game *game, double x_od, double x_op)
{
	if (game->status.rotate_left && !game->status.rotate_right)
	{
		game->player.dir_x = game->player.dir_x * cos(0.05)
		- game->player.dir_y * sin(0.05);
		game->player.dir_y = x_od * sin(0.05)
		+ game->player.dir_y * cos(0.05);
		game->player.plane_x = game->player.plane_x * cos(0.05)
		- game->player.plane_y * sin(0.05);
		game->player.plane_y = x_op * sin(0.05)
		+ game->player.plane_y * cos(0.05);
	}
	else if (game->status.rotate_right && !game->status.rotate_left)
	{
		game->player.dir_x = game->player.dir_x * cos(-0.05)
		- game->player.dir_y * sin(-0.05);
		game->player.dir_y = x_od * sin(-0.05)
		+ game->player.dir_y * cos(-0.05);
		game->player.plane_x = game->player.plane_x * cos(-0.05)
		- game->player.plane_y * sin(-0.05);
		game->player.plane_y = x_op * sin(-0.05)
		+ game->player.plane_y * cos(-0.05);
	}
}

static void	move(t_game *game)
{
	if (game->status.move_forwards && !game->status.move_backwards)
	{
		game->player.pos_x += game->player.dir_x * game->player.speed;
		game->player.pos_y += game->player.dir_y * game->player.speed;
		if (game->map[(int)game->player.pos_x][(int)game->player.pos_y])
		{
			game->player.pos_x -= game->player.dir_x * game->player.speed;
			game->player.pos_y -= game->player.dir_y * game->player.speed;
		}
	}
	else if (game->status.move_backwards && !game->status.move_forwards)
	{
		game->player.pos_x -= game->player.dir_x * game->player.speed;
		game->player.pos_y -= game->player.dir_y * game->player.speed;
		if (game->map[(int)game->player.pos_x][(int)game->player.pos_y])
		{
			game->player.pos_x += game->player.dir_x * game->player.speed;
			game->player.pos_y += game->player.dir_y * game->player.speed;
		}
	}
}

int			hook(t_game *game)
{
	move(game);
	rotate(game, game->player.dir_x, game->player.plane_x);
	draw_game(game);
	return (0);
}
