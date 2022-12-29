/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:28:27 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/29 16:05:01 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_position(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	else if (game->map[y][x] == 'C')
	{
		game->collects_taken++;
		game->map[y][x] = '0';
		return (1);
	}
	else if (game->map[y][x] == 'E')
	{
		if (game->collects_taken != game->count_collects)
			return (0);
		else
		{
			game->count_movements++;
			ft_printf("%d\n", game->count_movements);
			end_game(game);
		}
	}
	game->count_movements++;
	ft_printf("%d\n", game->count_movements);
	return (1);
}

void	player_animation(t_game *game, int direction)
{
	if (direction == RIGHT || direction == DRIGHT)
		move_right(game);
	else if (direction == LEFT || direction == ALEFT)
		move_left(game);
	else if (direction == UP || direction == WUP)
		move_up(game);
	else if (direction == DOWN || direction == SDOWN)
		move_down(game);
}
