/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:26:16 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/30 20:29:22 by tde-melo         ###   ########.fr       */
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
		game->count_collects = count_collects(map);
		create_sprites(game);
		draw_map(game);
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
		return (0);
	map = ft_split(str, '\n');
	if (validate_map(map))
	{
		free_map(map);
		map = ft_split(str, '\n');
		initialize_game(game, map);
		close(fd);
		free(str);
		return (1);
	}
	close(fd);
	free_map(map);
	free(str);
	return (0);
}
