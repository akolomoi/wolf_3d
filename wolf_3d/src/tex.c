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

static int to_gray(int a)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t b;

	b = a;
	g = (a >> 8);
	r = (a >> 16);
	b = (uint8_t)(b * 0.2);
	g = (uint8_t)(g * 0.2);
	r = (uint8_t)(r * 0.2);
	return ((r << 16) + (g << 8) + b);
}

void	load_textures(t_game *game)
{
	int	i;
	int	j;

	i = TEX_SIZE;
	j = TEX_SIZE;
	game->try2 = mlx_xpm_file_to_image(game->mlx, "../textures/stone.bmp", &i, &j);
	i = -1;
	int c = 0x111111 / 48;
	int	k = 0;
	while (++i < TEX_SIZE && (j = -1))
		while (++j < TEX_SIZE)
			if (i % 3 == 1)
				game->textures[j][i] = to_gray(j % 5 ? 0x0a0a0a * (j & i) : 0x000007);
			else if (i % 3 == 2)
				game->textures[j][i] = to_gray(j % 2 ? 0x0a0a0a * (j | i) : 0x000007);
			else
				game->textures[j][i] = to_gray(j % 3 ? 0x0a0a0a * (i ^ j) : 0x000003);
}

int		init_tex(t_game *game, t_dda *a)
{
	a->wx = a->side ? game->player.pos_x + a->wd * a->x_rd
	: game->player.pos_y + a->wd * a->y_rd;
	a->wx -= floor(a->wx);
	a->cx = (int)(a->wx * TEX_SIZE);
	if ((!a->side && a->x_rd > 0) || (a->side && a->y_rd < 0))
		a->cx = TEX_SIZE - a->cx - 1;
	return (0);
}


int		go_textured(t_game *game, t_dda a, int y)
{
	int smh;

	smh = (y << 9) - (W_HEIGHT << 8) + (a.lh << 8);
	smh = ((smh * TEX_SIZE) / a.lh) >> 9;
	return (fade(game->textures[a.cx][smh], a.wd));
}