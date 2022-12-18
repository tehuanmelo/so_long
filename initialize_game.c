/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:26:16 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/19 00:13:09 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *read_map(char *str, int fd)
{
    char *buffer;
    ssize_t flag;

    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    flag = 1;
    while (flag)
    {
        flag = read(fd, buffer, BUFFER_SIZE);
        buffer[flag] = 0;
        if (flag == -1)
        {
            free(buffer);
            return (0);
        }
        str = ft_strjoin(str, buffer);
    }
    free(buffer);
    return (str);
}

int is_ber(char *file_ber)
{
    char *str;

    str = ft_strrchr(file_ber, '.');
    if (ft_strlen(str) == 4)
    {
        if (!(ft_strncmp(str, ".ber", 3)))
            return 1;
    }
    ft_printf("Error! File .ber not found");
    return 0;
}

t_position get_window_dimension(char **map)
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
    int map_is_valid;
    char *str;
    char *map_ber;
    char **map;
    t_game game;

    map_ber = ft_strjoin("./map/", file_ber);
    str = malloc(sizeof(char));
    fd = open(map_ber, O_RDONLY);
    str = read_map(str, fd);
    map = ft_split(str, '\n');
    free(str);

    map_is_valid = validate_map(map);
    if (map_is_valid)
    {
        game.window_dimension = get_window_dimension(map);
        game.map = map;
        game.mlx = mlx_init();
        game.error = 0;
        game.win = mlx_new_window(game.mlx, game.window_dimension.x, game.window_dimension.y, "So_long!");
    }
    else
        game.error = 1;
    return game;
}