/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolomoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 18:00:41 by akolomoi          #+#    #+#             */
/*   Updated: 2019/05/11 18:00:42 by akolomoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include <libc.h>

static void put_pixel(t_game *game, int x, int y, int c)
{
    int     tmp;

    tmp = 32;
    game->img_adr = mlx_get_data_addr(game->img, &tmp, &tmp, &tmp);
    *(int*)(game->img_adr + sizeof(int) * (x + y * W_WIDTH)) = c;
}

static int fade(int color, double dist)
{
    uint8_t     r;
    uint8_t     g;
    uint8_t     b;
    int         k;

    if (dist > 25)
        dist = 25;
    b = color >> 16;
    g = color >> 8;
    r = color;
    dist /= 25.0;
    b -= b * dist;
    g -= g * dist;
    r -= r * dist;
    return ((r << 16) + (g << 8) + b);
}

static int  get_col(int tile_value)
{
    if (tile_value == T_DOORWAY)
        return (0x2cb288);
    else if (tile_value == T_FRAGILE_1)
        return (0xE0FFFF);
    else if (tile_value == T_FRAGILE_2)
        return (0xa0a0a);
    else if (tile_value == T_FRAGILE_3)
        return (0xa0);
    else if (tile_value == T_SOLID_1)
        return (0xff);
    else if (tile_value == T_SOLID_2)
        return (0xff00);
    else if (tile_value == T_SOLID_3)
        return (0xff0000);
    else
        return (0x235476);
}

void        draw_vertical_line(t_game *game, t_dda a, int *prev_color, int x)
{
    int     i;

    i = -1;
    if (game->player.mode == M_SEPERATED)
        a.color = get_col(a.tv);
    while (++i < a.start)
        put_pixel(game, x, i, 0xE0FFFF);
    while (++a.start < a.end)
        put_pixel(game, x, a.start, (*prev_color == a.color
        ? fade(a.color, a.wd) : 0x0));
    while (++a.start < W_HEIGHT)
        put_pixel(game, x, a.start, 0xDEB887);
    *prev_color = a.color;
}
