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

//https://github.com/GlThibault/Wolf3D

int		game_keyboard(int k, t_game *game)
{
	if (k == KEY_ESC)
		game_exit(game);
    else if (k == KEY_LEFT)
    {
        double x_olddir, x_oldplane;
        x_olddir = game->player.dir_x;
        game->player.dir_x = game->player.dir_x * cos(0.05) - game->player.dir_y * sin(0.05);
        game->player.dir_y = x_olddir * sin(0.05) + game->player.dir_y * cos(0.05);
        x_oldplane = game->player.plane_x;
        game->player.plane_x = game->player.plane_x * cos(0.05) - game->player.plane_y * sin(0.05);
        game->player.plane_y = x_oldplane * sin(0.05) + game->player.plane_y * cos(0.05);
    }
    else if (k == KEY_RIGHT)
    {
        double x_olddir, x_oldplane;
        x_olddir = game->player.dir_x;
        game->player.dir_x = game->player.dir_x * cos(-0.05) - game->player.dir_y * sin(-0.05);
        game->player.dir_y = x_olddir * sin(-0.05) + game->player.dir_y * cos(-0.05);
        x_oldplane = game->player.plane_x;
        game->player.plane_x = game->player.plane_x * cos(-0.05) - game->player.plane_y * sin(-0.05);
        game->player.plane_y = x_oldplane * sin(-0.05) + game->player.plane_y * cos(-0.05);
    }
    else if (k == KEY_UP)
    {
        game->player.pos_x += game->player.dir_x * 0.1;
        game->player.pos_y += game->player.dir_y * 0.1;
        if (game->map[(int) game->player.pos_x][(int) game->player.pos_y])
        {
            game->player.pos_x -= game->player.dir_x * 0.1;
            game->player.pos_y -= game->player.dir_y * 0.1;
        }
    }
    else if (k == KEY_DOWN)
    {
        game->player.pos_x -= game->player.dir_x * 0.1;
        game->player.pos_y -= game->player.dir_y * 0.1;
        if (game->map[(int) game->player.pos_x][(int) game->player.pos_y])
        {
            game->player.pos_x += game->player.dir_x * 0.1;
            game->player.pos_y += game->player.dir_y * 0.1;
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

int     key_press(int k, t_game *game)
{
    if (k == KEY_UP)
        game->status.move_forwards = 1;
    else if (k == KEY_DOWN)
        game->status.move_backwards = 1;
    else if (k == KEY_LEFT)
        game->status.rotate_left = 1;
    else if (k == KEY_RIGHT)
        game->status.rotate_right = 1;
    else if (k == KEY_ESC)
        exit(1);
    return (0);
}

int     key_release(int k, t_game *game)
{
    if (k == KEY_UP)
        game->status.move_forwards = 0;
    else if (k == KEY_DOWN)
        game->status.move_backwards = 0;
    else if (k == KEY_LEFT)
        game->status.rotate_left = 0;
    else if (k == KEY_RIGHT)
        game->status.rotate_right = 0;
    return (0);
}

static void rotate(t_game *game)
{
    double x_olddir, x_oldplane;

    if (game->status.rotate_left)
    {
        x_olddir = game->player.dir_x;
        game->player.dir_x = game->player.dir_x * cos(0.05) - game->player.dir_y * sin(0.05);
        game->player.dir_y = x_olddir * sin(0.05) + game->player.dir_y * cos(0.05);
        x_oldplane = game->player.plane_x;
        game->player.plane_x = game->player.plane_x * cos(0.05) - game->player.plane_y * sin(0.05);
        game->player.plane_y = x_oldplane * sin(0.05) + game->player.plane_y * cos(0.05);
    }
    else if (game->status.rotate_right)
    {
        x_olddir = game->player.dir_x;
        game->player.dir_x = game->player.dir_x * cos(-0.05) - game->player.dir_y * sin(-0.05);
        game->player.dir_y = x_olddir * sin(-0.05) + game->player.dir_y * cos(-0.05);
        x_oldplane = game->player.plane_x;
        game->player.plane_x = game->player.plane_x * cos(-0.05) - game->player.plane_y * sin(-0.05);
        game->player.plane_y = x_oldplane * sin(-0.05) + game->player.plane_y * cos(-0.05);
    }
}

static void  move(t_game *game)
{
    if (game->status.move_forwards)
    {
        game->player.pos_x += game->player.dir_x * 0.1;
        game->player.pos_y += game->player.dir_y * 0.1;
        if (game->map[(int) game->player.pos_x][(int) game->player.pos_y])
        {
            game->player.pos_x -= game->player.dir_x * 0.1;
            game->player.pos_y -= game->player.dir_y * 0.1;
        }
    }
    else if (game->status.move_backwards)
    {
        game->player.pos_x -= game->player.dir_x * 0.1;
        game->player.pos_y -= game->player.dir_y * 0.1;
        if (game->map[(int) game->player.pos_x][(int) game->player.pos_y])
        {
            game->player.pos_x += game->player.dir_x * 0.1;
            game->player.pos_y += game->player.dir_y * 0.1;
        }
    }
}

int     hook(t_game *game)
{
    move(game);
    rotate(game);
    draw_game(game);
    return (0);
}

int		game_exit(t_game *param)
{
	param = (t_game*)param;
//	system("leaks -quiet wolf3d");

	exit(EXIT_SUCCESS);
	return (1);
}
