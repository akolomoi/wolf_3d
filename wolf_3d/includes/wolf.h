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

# define W_WIDTH	1000
# define W_HEIGHT	800

# define oMAP_SIZE	1024
#define  MAP_SIZE 	game->ms
# define TEX_SIZE	64

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

typedef enum	e_modes
{
	M_BOLD,
	M_SEPERATED,
	M_TEXTURED,
	M_TOTAL
}				t_modes;

typedef struct	s_dda
{
	double		x_cam;
	double		x_rp;
	double		y_rp;
	double		x_rd;
	double		y_rd;
	int			x_m;
	int			y_m;
	double		wd;
	double		x_sd;
	double		y_sd;
	double		x_dd;
	double		y_dd;
	int			x_st;
	int			y_st;
	int			side;
	int			hit;
	int			color;
	int			lh;
	int			start;
	int			end;
	int			tv;
	double		wx;
	int			cx;
}				t_dda;

typedef struct	s_player
{
	int			spawn_x;
	int			spawn_y;
	int			mode;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		speed;
}				t_player;

typedef struct	s_keys
{
	int			move_forwards;
	int			move_backwards;
	int			rotate_left;
	int			rotate_right;
}				t_keys;

typedef struct	s_tex
{
	void		*img;
	char		*adr;
}				t_tex;

typedef struct	s_game
{
	t_player	player;
	t_keys		status;
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_adr;
	int 		**map;
	int 		ms;
	int			omap[oMAP_SIZE][oMAP_SIZE];
	t_tex		tex[T_TOTAL];
}				t_game;

void			die(int reason);
void			warn(int reason);

int				create_window(t_game *window);
int				get_map(t_game *game, char *name);
int				set_spawn(t_game *game, int i, int j);
void			init_player(t_game *game);

int				hook(t_game *game);
int				key_release(int k, t_game *game);
int				key_press(int k, t_game *game);

void			load_textures(t_game *game);
int				init_tex(t_game *game, t_dda *a);
int				go_textured(t_game *game, t_dda a, int y);
int				fade(int color, double dist);

void			draw_vertical_line(t_game *game, t_dda a, int *prev_c, int x);
void			draw_game(t_game *game);

int				game_exit(t_game *param);

#endif
