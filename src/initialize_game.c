/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:26:16 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/01/06 12:41:24 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game_struct(t_game *game, char **map)
{
	game->window_dimension = get_window_dimension(map);
	game->map = map;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->window_dimension.x,
			game->window_dimension.y, "So_long!");
	game->count_movements = 0;
	game->collects_taken = 0;
	game->count_collects = count_collects(map);
	create_sprites(game);
	draw_map(game);
}

int	game_init(char *file_ber, t_game *game)
{
	int		fd;
	char	*str;
	char	**map;

	fd = open(file_ber, O_RDONLY);
	str = read_map(fd);
	if (fd == -1 || str == NULL)
		return (0);
	map = ft_split(str, '\n');
	if (validate_map(map))
	{
		free_map(map);
		map = ft_split(str, '\n');
		initialize_game_struct(game, map);
		close(fd);
		free(str);
		return (1);
	}
	close(fd);
	free_map(map);
	free(str);
	return (0);
}
