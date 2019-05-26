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

void	load_textures(t_game *game)
{
	int x;
	int y;

	x = 64;
	y = 64;
	void *t = mlx_xpm_file_to_image(game->mlx, "../textures/stone.xpm", &x, &y);
}

int		go_textured(t_game *game, t_dda a, int x, int y)
{
	return (0);
}
