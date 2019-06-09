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

static int	map_alloc(t_game *game, int size) {
	int i;
	int	j;

	i = -1;
	if (size < 4)
		die(NOT_ENOUGH_SPACE);
	game->ms = size;
	if (!(game->map = (int**)malloc(sizeof(int*) * (size))))
		return (BIG_MAP);
	while (++i < size)
		if (!(game->map[i] = (int*)malloc(sizeof(int) * (size))))
			return (BIG_MAP);
	i = -1;
	while (++i < size && (j = -1))
		while (++j < size)
			if (i == 0 || j == 0 || i == size - 1 || j == size - 1)
				game->map[i][j] = T_MAP_EDGE;
			else
				game->map[i][j] = T_EMPTY;
	return (0);
}

static int	map_init(t_game *game, int fd)
{
	int		i;
	int		j;
	int 	r;
	char	buf[1];

	i = 0;
	j = 0;
	r = 0;
	while (read(fd, buf, 1))
		if (buf[0] != ' ')
		{
			if (buf[0] == '\n')
			{
				r = r < i ? i : r;
				i = 0;
				j++;
			}
			else
			{
				if (!ft_isdigit(buf[0]))
					die(UNKNOWN_SYMBOLS);
				i++;
			}
		}
	return (map_alloc(game, (r > j ? r : j) + 2));
}

static void	init_player_pos(int *player, t_game *game, int i, int j)
{
	*player += 1;
	if (*player == 1)
	{
		game->player.spawn_x = j;
		game->player.spawn_y = i;
	}
	game->map[j][i] = T_EMPTY;
}

static int	parse(const int fd, t_game *game, int j, int *player)
{
	char	buf[1];
	char 	prev;
	int		i;

	i = 1;
	while (read(fd, buf, 1))
		if (buf[0] != ' ')
		{
			if (buf[0] == '\n' && prev != '\n')
			{
				i = 1;
				j++;
			}
			else if (buf[0] != '\n')
			{
				if (!ft_isdigit(buf[0]))
					return (UNKNOWN_SYMBOLS);
				game->map[j][i++] = buf[0] - '0';
				if ((buf[0] - '0') == PLAYER)
					init_player_pos(player, game, i - 1, j);
			}
			prev = buf[0];
		}
	return (0);
}

int			get_map(t_game *game, char *name)
{
	int		fd;
	int		error;
	int		player;

	if ((fd = open(name, O_RDONLY)) == -1)
		die(BAD_MAP_NAME);
	if (map_init(game, fd))
		die(BIG_MAP);
	close(fd);
	if ((fd = open(name, O_RDONLY)) == -1)
		die(BAD_MAP_NAME);
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

/*
static void	map_init(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MAP_SIZE && (j = -1))
		while (++j < MAP_SIZE)
		{
			if (i == 0 || j == 0 || i == MAP_SIZE - 1 || j == MAP_SIZE - 1)
				game->map[i][j] = T_MAP_EDGE;
			else
				game->map[i][j] = T_EMPTY;
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
	game->map[j][i] = T_EMPTY;
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
					return (UNKNOWN_SYMBOLS);
				if (i >= MAP_SIZE - 2 || j >= MAP_SIZE - 2)
					return (BIG_MAP);
				game->map[j][i++] = buf[0] - '0';
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
			if (game->map[i][j] == 0)
			{
				game->player.spawn_x = j;
				game->player.spawn_y = i;
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
}*/
