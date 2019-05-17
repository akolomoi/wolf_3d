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

static int bad_trip(int color, double dist)
{
    int     r;
    int     g;
    int     b;

    b = color >> 16;
    g = color >> 8;
    r = color;
    b -= b * dist;
    g -= g * dist;
    r -= r * dist;
    return ((r << 16) + (g << 8) + b);
}

void    draw_game(t_game *game)
{

    int x = -1;
    int prev_color = 0;
    while (++x < W_WIDTH)
    {
        double x_cam = (x / (double)W_WIDTH) * 2 - 1;
        double x_raypos = game->player.pos_x;
        double y_raypos = game->player.pos_y;
        double x_raydir = game->player.dir_x + game->player.plane_x * x_cam;
        double y_raydir = game->player.dir_y + game->player.plane_y * x_cam;
        int x_map = (int)x_raypos;
        int y_map = (int)y_raypos;
        double walldist, x_sidedist, y_sidedist;

        //!dda init

        double x_deltadist = sqrt(1 + (y_raydir * y_raydir) / (x_raydir * x_raydir));
        double y_deltadist = sqrt(1 + (x_raydir * x_raydir) / (y_raydir * y_raydir));

        int x_step, y_step, side;

        if (x_raydir < 0)
        {
            x_step = -1;
            x_sidedist = (x_raypos - x_map) * x_deltadist;
        }
        else
        {
            x_step = 1;
            x_sidedist = (x_map + 1.0 - x_raypos) * x_deltadist;
        }
        if (y_raydir < 0)
        {
            y_step = -1;
            y_sidedist = (y_raypos - y_map) * y_deltadist;
        }
        else
        {
            y_step = 1;
            y_sidedist = (y_map + 1.0 - y_raypos) * y_deltadist;
        }

        //!dda

        int hit = 0;

        while (hit == 0 && x_map >= 0 && x_map <= MAP_SIZE && y_map >= 0 && y_map <= MAP_SIZE)
        {
            if (x_sidedist < y_sidedist)
            {
                x_sidedist += x_deltadist;
                x_map += x_step;
                side = 0;
            }
            else
            {
                y_sidedist += y_deltadist;
                y_map += y_step;
                side = 1;
            }
            if (game->map[x_map][y_map])
                hit = 1;
        }

        //!rc intit

        if (side == 0)
            walldist = (x_map - x_raypos + (1 - x_step) / 2) / x_raydir;
        else
            walldist = (y_map - y_raypos + (1 - y_step) / 2) / y_raydir;

        //
        int color;

        int lineheight = (int)(W_HEIGHT / walldist);
        int start = -lineheight / 2 + W_HEIGHT / 2;
        int end = lineheight / 2 + W_HEIGHT / 2;
        if (start < 0)
            start = 0;
        if (end >= W_WIDTH)
            end = W_HEIGHT - 1;

        if (side)
        {
            if (y_step == -1 )
                color = 0x4169E1;
            else
                color = 0x9100;
        }
        else
        {
            if (x_step == -1)
                color = 0xFF6347;
            else
                color = 0x99cc99;
        }
        //!verline
//TODO: rgb channels decrementing on distance increasing
        start--;
        int tmp = 32;
        game->img_adr = mlx_get_data_addr(game->img, &tmp, &tmp, &tmp);
        //printf("segf\n");
        int f = -1;
        while (++f < start)
            *(int*)(game->img_adr + sizeof(int) * (x + f * W_WIDTH)) = 0xE0FFFF;
        while (++start < end)
        {
            if (prev_color == color)
                *(int *) (game->img_adr + sizeof(int) * (x + start * W_WIDTH)) = fade(color, walldist);
            else
                *(int *) (game->img_adr + sizeof(int) * (x + start * W_WIDTH)) = 0;
        }
        while (++start < W_HEIGHT)
            *(int*)(game->img_adr + sizeof(int) * (x + start * W_WIDTH)) = 0xDEB887;

        prev_color = color;
        //!verline

    }
    mlx_put_image_to_window(game->mlx, game->win,game->img, 0, 0);
    ft_bzero(game->img_adr, sizeof(int) * W_HEIGHT * W_WIDTH);
}
