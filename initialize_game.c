/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:26:16 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/21 22:34:38 by tehuanmelo       ###   ########.fr       */
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
        if (!(ft_strncmp(str, ".ber", 4)))
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

void initialize_game_struct(t_game *game, char **map)
{
    game->window_dimension = get_window_dimension(map);
    game->map = map;
    game->mlx = mlx_init();
    game->error = 0;
    game->win = mlx_new_window(game->mlx, game->window_dimension.x, game->window_dimension.y, "So_long!");
    game->count_movements = 0;
    game->exit_count = 0;
    game->player_count = 0;
    game->collects_taken = 0;
}

void initialize_map(t_game *game)
{
    create_sprites(game);
    draw_map(game);
    if (game->player_count != 1)
        game->error = 1;
    else if (game->exit_count != 1)
        game->error = 1;
}

int game_init(char *file_ber, t_game *game)
{
    int fd;
    char *str;
    char *map_ber_path;
    char **map;

    map_ber_path = ft_strjoin("./map/", file_ber);
    str = "";
    fd = open(map_ber_path, O_RDONLY);
    if (fd != -1)
    {
        str = read_map(str, fd);
        map = ft_split(str, '\n');
        if (validate_map(map))
        {
            str = read_map(str, fd);
            map = ft_split(str, '\n');
            initialize_game_struct(game, map);
            initialize_map(game);
            close(fd);
            free(str);
            return 1;
        }
        close(fd);
        free(str);
    }
    return 0;
}