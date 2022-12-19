/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:21:51 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/19 16:36:23 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// ----->If the map contains 2 players or 2 exits display an error message
// -----> The map must be rectangular.
// -----> The map must be closed/surrounded by walls. If it’s not, the program must return
// an error.
// -----> You have to check if there’s a valid path in the map.
// -----> You must be able to parse any kind of map, as long as it respects the above rules.
// -----> If any misconfiguration of any kind is encountered in the file, the program must
// exit in a clean way, and return "Error\n" followed by an explicit error message of
// your choice.

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
			}
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