/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:21:51 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/22 17:45:31 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_background(t_game *game)
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

void draw_map(t_game *game)
{
	int i;
	int j;
	char element;

	draw_background(game);
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
				game->player_position.x = j;
				game->player_position.y = i;
			}
		j++;
		}

	i++;
	}
}