/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:31:30 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/27 17:58:05 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	create_image(t_game *game, char type)
{
	t_image	image;

	image.height = 50;
	image.width = 50;
	if (type == '0')
		image.path = LAND;
	else if (type == '1')
		image.path = WALL;
	else if (type == 'P')
		image.path = WALK_RIGHT;
	else if (type == 'L')
		image.path = WALK_LEFT;
	else if (type == 'U')
		image.path = WALK_UP;
	else if (type == 'D')
		image.path = WALK_DOWN;
	else if (type == 'E')
		image.path = EXIT;
	else if (type == 'C')
		image.path = COLLECT;
	image.img = mlx_xpm_file_to_image(game->mlx, image.path, &image.width,
			&image.height);
	return (image);
}

void	create_sprites(t_game *game)
{
	game->sprites.collect = create_image(game, 'C');
	game->sprites.player_right = create_image(game, 'P');
	game->sprites.player_left = create_image(game, 'L');
	game->sprites.player_up = create_image(game, 'U');
	game->sprites.player_down = create_image(game, 'D');
	game->sprites.exit = create_image(game, 'E');
	game->sprites.wall = create_image(game, '1');
	game->sprites.land = create_image(game, '0');
}

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
