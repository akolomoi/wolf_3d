/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 16:43:26 by akolomoi          #+#    #+#             */
/*   Updated: 2019/05/26 16:43:28 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include <libc.h>

static void	lt2(t_game *game, int i, int j, int k)
{
	game->tex[T_FRAGILE_1].img = mlx_xpm_file_to_image(game->mlx,
	"textures/Sand.xpm", &i, &j);
	game->tex[T_FRAGILE_1].adr = mlx_get_data_addr(game->tex[T_FRAGILE_1].img
	, &k, &k, &k);
	game->tex[T_FRAGILE_2].img = mlx_xpm_file_to_image(game->mlx,
	"textures/WoolSnow.xpm", &i, &j);
	game->tex[T_FRAGILE_2].adr = mlx_get_data_addr(game->tex[T_FRAGILE_2].img
	, &k, &k, &k);
	game->tex[T_FRAGILE_3].img = mlx_xpm_file_to_image(game->mlx,
	"textures/Planks.xpm", &i, &j);
	game->tex[T_FRAGILE_3].adr = mlx_get_data_addr(game->tex[T_FRAGILE_3].img
	, &k, &k, &k);
	game->tex[T_MAP_EDGE].img = mlx_xpm_file_to_image(game->mlx,
	"textures/LeavesOP.xpm", &i, &j);
	game->tex[T_MAP_EDGE].adr = mlx_get_data_addr(game->tex[T_MAP_EDGE].img
	, &k, &k, &k);
	game->tex[T_DOORWAY].img = mlx_xpm_file_to_image(game->mlx,
	"textures/bookshelf.xpm", &i, &j);
	game->tex[T_DOORWAY].adr = mlx_get_data_addr(game->tex[T_DOORWAY].img
	, &k, &k, &k);
}

void		load_textures(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = TEX_SIZE;
	j = TEX_SIZE;
	k = 32;
	game->tex[T_SOLID_1].img = mlx_xpm_file_to_image(game->mlx,
	"textures/Bricks.xpm", &i, &j);
	game->tex[T_SOLID_1].adr = mlx_get_data_addr(game->tex[T_SOLID_1].img
	, &k, &k, &k);
	game->tex[T_SOLID_2].img = mlx_xpm_file_to_image(game->mlx,
	"textures/Stone.xpm", &i, &j);
	game->tex[T_SOLID_2].adr = mlx_get_data_addr(game->tex[T_SOLID_2].img
	, &k, &k, &k);
	game->tex[T_SOLID_3].img = mlx_xpm_file_to_image(game->mlx,
	"textures/wood.xpm", &i, &j);
	game->tex[T_SOLID_3].adr = mlx_get_data_addr(game->tex[T_SOLID_3].img
	, &k, &k, &k);
	lt2(game, i, j, k);
}

int			init_tex(t_game *game, t_dda *a)
{
	a->wx = a->side ? game->player.pos_x + a->wd * a->x_rd
	: game->player.pos_y + a->wd * a->y_rd;
	a->wx -= floor(a->wx);
	a->cx = (int)(a->wx * TEX_SIZE);
	if ((!a->side && a->x_rd > 0) || (a->side && a->y_rd < 0))
		a->cx = TEX_SIZE - a->cx - 1;
	return (0);
}

int			go_textured(t_game *game, t_dda a, int y)
{
	int smh;

	smh = (y << 9) - (W_HEIGHT << 8) + (a.lh << 8);
	smh = ((smh * TEX_SIZE) / a.lh) >> 9;
	return (fade(*(int*)(game->tex[a.tv].adr +
	sizeof(int) * (a.cx + smh * TEX_SIZE)), a.wd));
}
