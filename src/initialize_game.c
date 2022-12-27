/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:26:16 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/27 23:53:25 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game(t_game *game, char **map)
{
	game->window_dimension = get_window_dimension(map);
	game->map = map;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->window_dimension.x,
			game->window_dimension.y, "So_long!");
	game->count_movements = 0;
	game->collects_taken = 0;
	create_sprites(game);
	draw_map(game);
}

void	free_map(char **map)
{
	int	i;

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
	int		fd;
	char	*str;
	char	**map;
	
	str = malloc(sizeof(char));
	str[0] = '\0';
	fd = open(file_ber, O_RDONLY);
	str = read_map(str, fd);
	if (fd == -1 || str == NULL)
		return 0;
	map = ft_split(str, '\n');
	if (validate_map(map))
	{
		free_map(map);
		map = ft_split(str, '\n');
		initialize_game(game, map);
	}
	else
	{
		free_map(map);
		return 0;
	}
	close(fd);
	free(str);
	return (1);
}
