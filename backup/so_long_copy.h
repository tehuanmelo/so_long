/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 23:55:30 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/15 23:04:02 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./mlx/mlx.h"

#define BUFFER_SIZE 1000

#define WALL "./sprites/wall.xpm"
#define LAND "./sprites/land.xpm"
#define EXIT "./sprites/exit.xpm"
#define COLLECT "./sprites/collect.xpm"
#define ENEMY "./sprites/enemy.xpm"
#define PLAYER "./sprites/player.xpm"


typedef struct s_window
{
	void *mlx;
	void *win;
    int height;
    int width;
} t_window;

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

enum key_code
{
    ESC = 53,
    LEFT = 123,
    RIGHT = 124,
    UP = 126,
    DOWN = 125
};


#endif