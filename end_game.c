/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:03:36 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/20 12:08:08 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void end_game(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_image(game->mlx, game->sprites.collect.img);
    mlx_destroy_image(game->mlx, game->sprites.player.img);
    mlx_destroy_image(game->mlx, game->sprites.wall.img);
    mlx_destroy_image(game->mlx, game->sprites.land.img);
}