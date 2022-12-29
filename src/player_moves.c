/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:28:27 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/29 18:32:58 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_right(t_game *game)
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

static void	move_left(t_game *game)
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

static void	move_up(t_game *game)
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

static void	move_down(t_game *game)
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

void	player_moves(t_game *game, int direction)
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
