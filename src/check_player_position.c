/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:28:27 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/29 17:54:30 by tde-melo         ###   ########.fr       */
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
		game->count_movements++;
		ft_printf("%d\n", game->count_movements);
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
