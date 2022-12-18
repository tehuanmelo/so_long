/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:26:16 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/18 20:16:05 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_position get_dimension(char **map)
{
    int i;
    int j;
    t_position dimension;

    i = 0;
    while (map[i])
	{
		j = 0;
		while (map[0][j])
			j++;
		i++;
	}
    dimension.x = j * 50;
    dimension.y = i * 50;
    return dimension;
}

t_game game_init(char *file_ber)
{
    int fd;
	char *str;
    char *map_ber;
    char **map;
    t_game game;
    
    map_ber = ft_strjoin("./map/", file_ber);
    str = malloc(sizeof(char));
    fd = open(map_ber, O_RDONLY);
	str = read_map(str, fd);
	map = ft_split(str, '\n');  
    
    game.window_dimension = get_dimension(map);
    game.map = map;
    game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.window_dimension.x, game.window_dimension.y, "So_long!");
    free(str);

    return game;
    
}