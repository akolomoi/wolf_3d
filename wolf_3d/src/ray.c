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

void    draw_game(t_game *game)
{
    // !must be smaller then player's speed
    double step = 0.1;
    //from 0 to W_WIDTH: trace distances

    //angle step
    double a_step = game->player.fov / W_WIDTH;

    //view boundaries
    double a_start = game->player.dir - game->player.fov / 2;
    double a_end = game->player.dir + game->player.fov / 2;

    //for each column of the window trace distances
    int i = -1;
    while (++i < W_WIDTH)
    {
        int tile_val;
        //get the ray angle
        double ray = a_start + a_step * i;
        double distance = 0.0;
        //get the unit vector
        double unit_x = ray * sin(ray);
        double unit_y = ray * cos(ray);
        int hit = 0;
        //TODO: out_of_bounds
        while (!hit && distance < MAP_SIZE - 2)
        {
            distance += step;

            int try_x = (int)(game->player.pos_x + unit_x * distance);
            int try_y = (int)(game->player.pos_y + unit_y * distance);
            if ((tile_val = game->info.map[try_x][try_y]) && tile_val != PLAYER)
            {
                draw_vertical_line(game, i, distance * cos(ray), tile_val);
                printf("segf\n");
                break ;
            }
        }
    }
    mlx_put_image_to_window(game->win.mlx, game->win.win,game->win.img, 0, 0);
    ft_bzero(game->win.img_adr, sizeof(int) * W_HEIGHT * W_WIDTH);
}