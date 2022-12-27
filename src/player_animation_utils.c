/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:28:27 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/22 20:32:57 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_game *game)
{
	int	valid_position;
	int	new_x_position;

	new_x_position = game->player_position.x + 1;
	valid_position = check_position(game, new_x_position,
			game->player_position.y);
	if (valid_position)
	{
		draw_image(game, '0', game->player_position.x, game->player_position.y);
		draw_image(game, '0', new_x_position, game->player_position.y);
		draw_image(game, 'P', new_x_position, game->player_position.y);
		game->player_position.x = new_x_position;
	}
}

void	move_left(t_game *game)
{
	int	valid_position;
	int	new_x_position;

	new_x_position = game->player_position.x - 1;
	valid_position = check_position(game, new_x_position,
			game->player_position.y);
	if (valid_position)
	{
		draw_image(game, '0', game->player_position.x, game->player_position.y);
		draw_image(game, '0', new_x_position, game->player_position.y);
		draw_image(game, 'L', new_x_position, game->player_position.y);
		game->player_position.x = new_x_position;
	}
}

void	move_up(t_game *game)
{
	int	valid_position;
	int	new_y_position;

	new_y_position = game->player_position.y - 1;
	valid_position = check_position(game, game->player_position.x,
			new_y_position);
	if (valid_position)
	{
		draw_image(game, '0', game->player_position.x, game->player_position.y);
		draw_image(game, '0', game->player_position.x, new_y_position);
		draw_image(game, 'U', game->player_position.x, new_y_position);
		game->player_position.y = new_y_position;
	}
}

void	move_down(t_game *game)
{
	int	valid_position;
	int	new_y_position;

	new_y_position = game->player_position.y + 1;
	valid_position = check_position(game, game->player_position.x,
			new_y_position);
	if (valid_position)
	{
		draw_image(game, '0', game->player_position.x, game->player_position.y);
		draw_image(game, '0', game->player_position.x, new_y_position);
		draw_image(game, 'D', game->player_position.x, new_y_position);
		game->player_position.y = new_y_position;
	}
}
