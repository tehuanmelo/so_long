/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:05:47 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/23 22:32:28 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		end_game(game);
	else
		player_animation(game, keycode);
	return (0);
}

int	main(int ac, char **av)
{
	int		start_game;
	t_game	game;

	if (ac == 2 && is_ber(av[1]))
	{
		start_game = game_init(av[1], &game);
		if (!start_game)
			return (1);
		mlx_key_hook(game.win, key_hook, &game);
		mlx_hook(game.win, 17, 0, end_game, &game);
		mlx_loop(game.mlx);
	}
	else
		return (1);
	return (0);
}
