/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:31:30 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/19 16:19:43 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


t_image create_image(t_game *game, char type)
{
	// void *image_pointer;
	t_image image;

	// image_pointer = &image;
	image.height = 50;
	image.width = 50;

	if (type == '0')
		image.path = LAND;
	else if (type == '1')
		image.path = WALL;
	else if (type == 'P')
		image.path = PLAYER;
	else if (type == 'E')
		image.path = EXIT;
	else if (type == 'C')
		image.path = COLLECT;

	image.img = mlx_xpm_file_to_image(game->mlx, image.path, &image.width, &image.height);

	return image;
}

void create_sprites(t_game *game)
{
	game->sprites.collect = create_image(game, 'C');
	game->sprites.player = create_image(game, 'P');
	game->sprites.exit = create_image(game, 'E');
	game->sprites.wall = create_image(game, '1');
	game->sprites.land = create_image(game, '0');

}

void draw_image(t_game *game, char type, int x, int y)
{
	if (type == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.land.img, x * 50, y * 50);
	else if (type == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.wall.img, x * 50, y * 50);
	else if (type == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.collect.img, x * 50, y * 50);
	else if (type == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.exit.img, x * 50, y * 50);
	else if (type == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.player.img, x * 50, y * 50);
}