/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:21:51 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/29 18:32:00 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_image(t_game *game, char type, int x, int y)
{
	if (type == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.land.img, x
			* 50, y * 50);
	else if (type == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.wall.img, x
			* 50, y * 50);
	else if (type == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.collect.img,
			x * 50, y * 50);
	else if (type == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.exit.img, x
			* 50, y * 50);
	else if (type == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprites.player_right.img, x * 50, y * 50);
	else if (type == 'L')
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprites.player_left.img, x * 50, y * 50);
	else if (type == 'U')
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprites.player_up.img, x * 50, y * 50);
	else if (type == 'D')
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprites.player_down.img, x * 50, y * 50);
}
