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
    printf("x = %d, y = %d, c = %lu\n", x, y, sizeof(int));
    *(int*)(game->win.img_adr + sizeof(int) * (x + y * W_WIDTH)) = c;
    printf("segf\n");
}

static int  get_col(int tile_value)
{
    if (tile_value == T_DOORWAY)
        return (C_DOORWAY);
    else if (tile_value == T_FRAGILE_1)
        return (C_FRAGILE_1);
    else if (tile_value == T_FRAGILE_2)
        return (C_FRAGILE_2);
    else if (tile_value == T_FRAGILE_3)
        return (C_FRAGILE_3);
    else if (tile_value == T_SOLID_1)
        return (C_SOLID_1);
    else if (tile_value == T_SOLID_2)
        return (C_SOLID_2);
    else if (tile_value == T_SOLID_3)
        return (C_SOLID_3);
    else if (tile_value == T_MAP_EDGE)
        return (C_MAP_EDGE);
    else
        return (C_EMPTY);
}

void        draw_vertical_line(t_game *game, int x, double d, int tile_val)
{
    int     start;
    int     end;
    int     l_height;

   //! d *= cos(ang);
    l_height = (int)(W_HEIGHT / d);
    start = -l_height / 2 + W_HEIGHT / 2;
    end = l_height / 2 + W_HEIGHT/ 2;
    if (start < 0)
        start = 0;
    if (end >= W_HEIGHT)
        end = W_HEIGHT - 1;

    int c = get_col(tile_val);

    int i = -1;
    while (++i < W_HEIGHT)
    {
        if (i < start)
            continue ;
        if (i > end)
            continue ;
        else
            put_pixel(game, x, i, c);
    }
}

