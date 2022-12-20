/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:05:47 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/20 19:29:51 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		end_game(game);
	else
		player_animation(game, keycode);

	return (0);
}

int main(int ac, char **av)
{
	if (ac == 2 && is_ber(av[1]))
	{
		t_game game;

		game_init(av[1], &game);
		if (game.error)
		{
			ft_printf("Error!\n");
			return 1;
		}
		
		mlx_key_hook(game.win, key_hook, &game);
		mlx_hook(game.win, 17, 0, end_game, &game);
		mlx_loop(game.mlx);
	}

	return 0;
}