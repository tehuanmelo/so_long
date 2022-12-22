/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 23:55:30 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/22 21:51:50 by tehuanmelo       ###   ########.fr       */
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
#include <stddef.h>
#include <errno.h>

#define BUFFER_SIZE 1000

#define WALL "./wall.xpm"
#define LAND "./land.xpm"
#define EXIT "./exit.xpm"
#define COLLECT "./collect.xpm"
#define WALK_RIGHT "./walk_right.xpm"
#define WALK_LEFT "./walk_left.xpm"
#define WALK_UP "./walk_up.xpm"
#define WALK_DOWN "./walk_down.xpm"


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
} t_image;

typedef struct s_sprite {
    t_image wall;
    t_image land;
    t_image player_right;
    t_image player_left;
    t_image player_up;
    t_image player_down;
    t_image collect;
    t_image exit;
} t_sprite;

typedef struct s_game
{
    void *mlx;
    void *win;
    char **map;
    int count_movements;
    int collects_taken;
    t_position window_dimension;
    t_position player_position;
    t_sprite sprites;
} t_game;

enum key_code
{
    ESC = 53,
    LEFT = 123,
    RIGHT = 124,
    UP = 126,
    DOWN = 125,
    ALEFT = 0,
    DRIGHT = 2,
    WUP = 13,
    SDOWN = 1
};

char    *read_map(char *str, int fd);
void    player_animation(t_game *game, int direction);
void    draw_map(t_game *game);
void    draw_image(t_game *game, char type, int x, int y);
void    create_sprites(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	initialize_game_struct(t_game *game, char **map);
int     is_ber(char *file_name);
int     game_init(char *file_ber, t_game *game);
int     validate_map(char **map);
int     end_game(t_game *game);
int	    check_position(t_game *game, int x, int y);
int	    check_walls(char **map);
int	    is_rectangular(char **map);
int	    validate_exit(char **map);
int	    validate_collects(char **map);
int	    check_map_char_struct(char **map);
t_image create_image(t_game *game, char type);
t_position	get_window_dimension(char **map);
char	*read_map(char *str, int fd);


#endif