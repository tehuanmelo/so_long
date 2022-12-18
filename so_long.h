/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 23:55:30 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/18 20:36:08 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
#define FT_SO_LONG_H

#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "./mlx/mlx.h"

#define BUFFER_SIZE 1000

#define WALL "./sprites/wall.xpm"
#define LAND "./sprites/land.xpm"
#define EXIT "./sprites/exit.xpm"
#define COLLECT "./sprites/collect.xpm"
#define PLAYER "./sprites/player.xpm"

typedef struct s_position
{
    int x;
    int y;
} t_position;

typedef struct s_image
{
    void *img;
    char *path;
    int width;
    int height;
    t_position position;
} t_image;

typedef struct s_player
{
    int movements;
    t_position position;
} t_player;

typedef struct s_game
{
    void *mlx;
    void *win;
    char **map;
    t_player player;
    t_position window_dimension;
} t_game;

enum key_code
{
    ESC = 53,
    LEFT = 123,
    RIGHT = 124,
    UP = 126,
    DOWN = 125
};

t_image create_image(t_game *game, char type);
t_game game_init(char *file_ber);
void player_animation(t_game *game, int direction);
char *read_map(char *str, int fd);
void write_background(t_game *game);
void write_elements(t_game *game);
void draw_image(t_game *game, char type, int x, int y);
int is_ber(char *file_ber);

#endif