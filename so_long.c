/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:05:47 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/19 00:13:23 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else
		player_animation(game, keycode);

	return (0);
}

int main(int ac, char **av)
{
	if (ac == 2 && is_ber(av[1]))
	{
		t_game game;

		game = game_init(av[1]);
		if (game.error)
			return 1;

		write_background(&game);
		write_elements(&game);

		mlx_key_hook(game.win, key_hook, &game);
		// mlx_loop_hook(game.mlx, update_screen, &game);
		mlx_loop(game.mlx);
	}

	return 0;
}