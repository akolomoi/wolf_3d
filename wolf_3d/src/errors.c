/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:48:50 by akolomoi          #+#    #+#             */
/*   Updated: 2019/04/01 18:48:51 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	init_player(t_game *game)
{
	game->player.pos_x = game->player.spawn_x + 0.5;
	game->player.pos_y = game->player.spawn_y + 0.5;
	game->player.dir_x = -1;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
	game->player.mode = M_BOLD;
	game->player.speed = 0.1;
}

int		game_exit(t_game *param)
{
	param = (t_game*)param;
	exit(EXIT_SUCCESS);
	return (1);
}

void	die(int reason)
{
	ft_putendl("Usage: ./wolf3d [map]");
	ft_putstr("(!) Error: ");
	if (reason == INVALID_PARAMS)
		ft_putendl("Invalid params.");
	else if (reason == BAD_MAP_NAME)
		ft_putendl("Bad map name.");
	else if (reason == TOO_MANY_PARAMS)
		ft_putendl("Too many params.");
	else if (reason == MLX_FAILED)
		ft_putendl("MLX failed.");
	else if (reason == BIG_MAP)
		ft_putendl("Map is too big.");
	else if (reason == UNKNOWN_SYMBOLS)
		ft_putendl("Map contains bad characters.");
	else if (reason == NOT_ENOUGH_SPACE)
		ft_putendl("Spawnpoint can not be set.");
	exit(1);
}

void	warn(int reason)
{
	ft_putstr("(?) Warning: ");
	if (reason == MANY_SPAWNPTS)
		ft_putendl("more than one spawnpoint is set.");
	else if (reason == SPAWNPOINT_NOT_SET)
		ft_putendl("spawnpoint is not set.");
}
