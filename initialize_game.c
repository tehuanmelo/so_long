/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:26:16 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/27 17:15:34 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_map(t_game *game)
{
	create_sprites(game);
	draw_map(game);
}

void free_map(char **map)
{
	int i;
	
	i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int	game_init(char *file_ber, t_game *game)
{
	int fd;
	char *str;
	char *map_ber_path;
	char **map_validation;
	char **map;

	map_ber_path = file_ber;
	str = malloc(sizeof(char));
	str[0] = '\0';
	fd = open(map_ber_path, O_RDONLY);
	if (fd != -1)
	{
		str = read_map(str, fd);
		map_validation = ft_split(str, '\n');
		if (validate_map(map_validation))
		{
			str = read_map(str, fd);
			map = ft_split(str, '\n');
			initialize_game_struct(game, map);
			initialize_map(game);
			close(fd);
			free(str);
			free_map(map_validation);
			return (1);
		}
		close(fd);
		free(map_validation);
	
	}
	else	
	{
		ft_printf("Error\n");
		perror("");
	}
	return (0);
}