/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:21:51 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/19 23:42:08 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void write_elements(t_game *game)
{
	int i;
	int j;
	char element;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			element = game->map[i][j];
			draw_image(game, element, j, i);
			if (element == 'P')
			{
				game->sprites.player.position.x = j;
				game->sprites.player.position.y = i;
				game->player_count++;
			}
			else if (element == 'C')
				game->collect_count++;
			else if (element == 'E')
				game->exit_count++;
			j++;
		}
		i++;
	}
}

void write_background(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			draw_image(game, '0', j, i);
			j++;
		}
		i++;
	}
}