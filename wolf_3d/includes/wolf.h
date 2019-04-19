/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 18:04:12 by akolomoi          #+#    #+#             */
/*   Updated: 2019/03/15 18:04:13 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>
# include "../libft/libft.h"

# define W_WIDTH	800
# define W_HEIGHT	600

# define MAP_SIZE	10	//256

typedef enum	e_errors
{
	MLX_FAILED = 1,
	INVALID_PARAMS,
	BIG_MAP,
	TOO_MANY_PARAMS,
	UNKNOWN_SYMBOLS,
	SPAWNPOINT_NOT_SET,
	BAD_MAP_NAME,
	NOT_ENOUGH_SPACE,
	MANY_SPAWNPTS
}				t_error;

typedef enum	e_tiles
{
	T_EMPTY,
	T_SOLID_1,
	T_SOLID_2,
	T_SOLID_3,
	T_FRAGILE_1,
	T_FRAGILE_2,
	T_FRAGILE_3,
	T_MAP_EDGE,
	T_DOORWAY,
	PLAYER,
	T_TOTAL
}				t_tiles;

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_adr;
}				t_window;


typedef struct	s_dda
{
	double		sdx;
	double		ddx;
	double		sdy;
	double		ddy;
	double		step_x;
	double		step_y;
	double		map_x;
	double		map_y;
}				t_dda;

typedef struct	s_player
{
	int			spawn_x;
	int			spawn_y;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		fov;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct	s_info
{
	int			map[MAP_SIZE][MAP_SIZE];
	int			is_running;
	double		time_old;
	double		time;
}				t_info;

typedef struct	s_game
{
	t_player	player;
	t_window	win;
	t_info		info;
	//int		textures[64][64][64];
}				t_game;

void			die(int reason);
void			warn(int reason);

int				get_map(t_game *game, char *name);
int				create_window(t_window	*window);
void			start_game(t_game *game);

int				game_keyboard(int k, t_game *game);
int				game_exit(t_game *param);

#endif
