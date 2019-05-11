/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:21:33 by akolomoi          #+#    #+#             */
/*   Updated: 2019/04/05 18:21:35 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include <libc.h>

static void	map_init(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MAP_SIZE && (j = -1))
		while (++j < MAP_SIZE)
		{
			if (i == 0 || j == 0 || i == MAP_SIZE - 1 || j == MAP_SIZE - 1)
				game->info.map[i][j] = T_MAP_EDGE;
			else
				game->info.map[i][j] = T_EMPTY;
		}
}

static void	init_player_pos(int *player, t_game *game, int i, int j)
{
	*player += 1;
	if (*player == 1)
	{
		game->player.spawn_x = j;
		game->player.spawn_y = i;
	}
	game->info.map[j][i] = T_EMPTY;
}

static int	parse(const int fd, t_game *game, int j, int *player)
{
	char	buf[1];
	int		i;

	i = 1;
	while (read(fd, buf, 1))
		if (buf[0] != ' ')
		{
			if (buf[0] == '\n')
			{
				i = 1;
				j++;
			}
			else
			{
				if (!ft_isdigit(buf[0]))
					return(UNKNOWN_SYMBOLS);
				if (i >= MAP_SIZE - 2 || j >= MAP_SIZE - 2)
					return(BIG_MAP);
				game->info.map[j][i++] = buf[0] - '0';
				if ((buf[0] - '0') == PLAYER)
					init_player_pos(player, game, i - 1, j);
			}
		}
	return (0);
}

static int	set_spawn(t_game *game, int i, int j)
{
	while (++i < MAP_SIZE && (j = -1))
		while (++j < MAP_SIZE)
			if (game->info.map[i][j] == 0)
			{
                game->player.spawn_x = j;
                game->player.spawn_y = i;
				game->info.map[i][j] = PLAYER;
				return (0);
			}
	return (1);
}

int			get_map(t_game *game, char *name)
{
	int		fd;
	int		error;
	int		player;

	if ((fd = open(name, O_RDONLY)) == -1)
		return (BAD_MAP_NAME);
	map_init(game);
	player = 0;
	if ((error = parse(fd, game, 1, &player)))
		die(error);
	if (player < 1)
	{
		warn(SPAWNPOINT_NOT_SET);	
		if (set_spawn(game, -1, -1))
			die(NOT_ENOUGH_SPACE);
	}
	else if (player > 1)
		warn(MANY_SPAWNPTS);
	return (1);
}
