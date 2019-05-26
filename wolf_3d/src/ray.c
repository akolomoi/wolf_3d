/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:10:05 by akolomoi          #+#    #+#             */
/*   Updated: 2019/04/19 18:10:11 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include <libc.h>

static t_dda	cycle(t_game *game, int x)
{
	t_dda	a;

	a.x_cam = (x / (double)W_WIDTH) * 2 - 1;
	a.x_rp = game->player.pos_x;
	a.y_rp = game->player.pos_y;
	a.x_rd = game->player.dir_x + game->player.plane_x * a.x_cam;
	a.y_rd = game->player.dir_y + game->player.plane_y * a.x_cam;
	a.x_m = (int)a.x_rp;
	a.y_m = (int)a.y_rp;
	a.x_dd = sqrt(1 + (a.y_rd * a.y_rd) / (a.x_rd * a.x_rd));
	a.y_dd = sqrt(1 + (a.x_rd * a.x_rd) / (a.y_rd * a.y_rd));
	a.x_st = a.x_rd < 0 ? -1 : 1;
	a.x_sd = a.x_dd * a.x_st * (a.x_m - a.x_rp + (a.x_st > 0 ? 1.0 : 0));
	a.y_st = a.y_rd < 0 ? -1 : 1;
	a.y_sd = a.y_dd * a.y_st * (a.y_m - a.y_rp + (a.y_st > 0 ? 1.0 : 0));
	a.hit = 0;
	return (a);
}

static void		dda(t_game *game, t_dda *a)
{
	while (!a->hit && a->x_m >= 0 && a->x_m <= MAP_SIZE && a->y_m >= 0
	&& a->y_m <= MAP_SIZE)
	{
		if (a->x_sd < a->y_sd)
		{
			a->x_sd += a->x_dd;
			a->x_m += a->x_st;
			a->side = 0;
		}
		else
		{
			a->y_sd += a->y_dd;
			a->y_m += a->y_st;
			a->side = 1;
		}
		if (game->map[a->x_m][a->y_m])
			a->hit = 1;
	}
	if (!a->side)
		a->wd = (a->x_m - a->x_rp + (1 - a->x_st) / 2) / a->x_rd;
	else
		a->wd = (a->y_m - a->y_rp + (1 - a->y_st) / 2) / a->y_rd;
	a->tv = game->map[a->x_m][a->y_m];
}

static void		line_prep(t_dda *a)
{
	a->lh = (int)(W_HEIGHT / a->wd);
	a->start = -a->lh / 2 + W_HEIGHT / 2 - 1;
	a->end = a->lh / 2 + W_HEIGHT / 2;
	if (a->start < 0)
		a->start = 0;
	if (a->end >= W_HEIGHT)
		a->end = W_HEIGHT - 1;
	if (a->side)
		a->color = a->y_st < 0 ? 0x4169E1 : 0x9100;
	else
		a->color = a->x_st < 0 ? 0xFF6347 : 0x99cc99;
}

void			draw_game(t_game *game)
{
	t_dda	a;
	int		x;
	int		prev_color;

	x = -1;
	prev_color = 0;
	while (++x < W_WIDTH)
	{
		a = cycle(game, x);
		dda(game, &a);
		line_prep(&a);
		draw_vertical_line(game, a, &prev_color, x);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	ft_bzero(game->img_adr, sizeof(int) * W_HEIGHT * W_WIDTH);
}
