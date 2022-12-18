/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:28:27 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/18 20:49:17 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_position(t_game *game, int x, int y)
{
    if (game->map[y][x] == '1')
        return 0;
    else
        return 1;
}

void move_right(t_game *game)
{
    int valid_position;
    int new_x_position;

    new_x_position = game->player.position.x + 1;
    valid_position = check_position(game, new_x_position, game->player.position.y);
    if (valid_position)
    {
        draw_image(game, '0', game->player.position.x, game->player.position.y);
        draw_image(game, '0', new_x_position, game->player.position.y);
        draw_image(game, 'P', new_x_position, game->player.position.y);
        game->player.position.x = new_x_position;
    }
}

void move_left(t_game *game)
{
    int valid_position;
    int new_x_position;

    new_x_position = game->player.position.x - 1;
    valid_position = check_position(game, new_x_position, game->player.position.y);
    if (valid_position)
    {
        draw_image(game, '0', game->player.position.x, game->player.position.y);
        draw_image(game, '0', new_x_position, game->player.position.y);
        draw_image(game, 'P', new_x_position, game->player.position.y);
        game->player.position.x = new_x_position;
    }
}

void move_up(t_game *game)
{
    int valid_position;
    int new_y_position;

    new_y_position = game->player.position.y - 1;
    valid_position = check_position(game, game->player.position.x, new_y_position);
    if (valid_position)
    {
        draw_image(game, '0', game->player.position.x, game->player.position.y);
        draw_image(game, '0', game->player.position.x, new_y_position);
        draw_image(game, 'P', game->player.position.x, new_y_position);
        game->player.position.y = new_y_position;
    }
}

void move_down(t_game *game)
{
    int valid_position;
    int new_y_position;

    new_y_position = game->player.position.y + 1;
    valid_position = check_position(game, game->player.position.x, new_y_position);
    if (valid_position)
    {
        draw_image(game, '0', game->player.position.x, game->player.position.y);
        draw_image(game, '0', game->player.position.x, new_y_position);
        draw_image(game, 'P', game->player.position.x, new_y_position);
        game->player.position.y = new_y_position;
    }
}

void player_animation(t_game *game, int direction)
{

    if (direction == RIGHT)
        move_right(game);
    else if (direction == LEFT)
        move_left(game);
    else if (direction == UP)
        move_up(game);
    else if (direction == DOWN)
        move_down(game);
}