/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:26:16 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/22 18:00:14 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(char *str, int fd)
{
	char	*buffer;
	ssize_t	flag;

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

t_position	get_window_dimension(char **map)
{
	int			i;
	int			j;
	t_position	dimension;

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
	return (dimension);
}

void	initialize_game_struct(t_game *game, char **map)
{
	game->window_dimension = get_window_dimension(map);
	game->map = map;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->window_dimension.x,
	game->window_dimension.y, "So_long!");
	game->count_movements = 0;
	game->collects_taken = 0;
}

void	initialize_map(t_game *game)
{
	create_sprites(game);
	draw_map(game);
}

int	game_init(char *file_ber, t_game *game)
{
	int fd;
	char *str;
	char *map_ber_path;
	char **map;

	map_ber_path = file_ber;
	str = "";
	fd = open(map_ber_path, O_RDONLY);
	if (fd > 0)
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
			return (1);
		}
		close(fd);
		free(str);
	}
	return (0);
}