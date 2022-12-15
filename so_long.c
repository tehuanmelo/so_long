/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:05:47 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/15 23:17:07 by tehuanmelo       ###   ########.fr       */
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

int key_hook(int keycode, t_window *window)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(window->mlx, window->win);
		exit(0);
	}
	return (0);
}

int main()
{
	int fd = open("./map/map.ber", O_RDONLY);
	char *str = "";
	str = read_map(str, fd);
	char **map = ft_split(str, '\n');
	int i = 0;
	int j = 0;
	
	
	while(map[i])
	{
		j = 0;
		while(map[0][j])
			j++;
		i++;	
	}

	printf("%d\n", i);
	printf("%d\n", j);

	t_window window;
	window.height = i * 50;
	window.width = j * 50;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, window.width, window.height, "So_long!");

	printf("%d\n", window.height);
	printf("%d\n", window.width);

	t_image land;
	land.height = 50;
	land.width = 50;
	land.path = LAND;
	land.img = mlx_xpm_file_to_image(window.mlx, land.path, &land.width, &land.height);

	t_image wall;
	wall.height = 50;
	wall.width = 50;
	wall.path = WALL;
	wall.img = mlx_xpm_file_to_image(window.mlx, wall.path, &wall.width, &wall.height);
	
	t_image player;
	player.height = 50;
	player.width = 50;
	player.path = PLAYER;
	player.img = mlx_xpm_file_to_image(window.mlx, player.path, &player.width, &player.height);
	
	t_image enemy;
	enemy.height = 50;
	enemy.width = 50;
	enemy.path = ENEMY;
	enemy.img = mlx_xpm_file_to_image(window.mlx, enemy.path, &enemy.width, &enemy.height);
	
	t_image exit;
	exit.height = 50;
	exit.width = 50;
	exit.path = EXIT;
	exit.img = mlx_xpm_file_to_image(window.mlx, exit.path, &exit.width, &exit.height);
	
	t_image collect;
	collect.height = 50;
	collect.width = 50;
	collect.path = COLLECT;
	collect.img = mlx_xpm_file_to_image(window.mlx, collect.path, &collect.width, &collect.height);
	

	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == '0')
			{
				mlx_put_image_to_window(window.mlx, window.win, land.img, j * 50, i * 50);
			}
			else if (map[i][j] == '1')
			{
				mlx_put_image_to_window(window.mlx, window.win, land.img, j * 50, i * 50);
				mlx_put_image_to_window(window.mlx, window.win, wall.img, j * 50, i * 50);
			}
			else if (map[i][j] == 'P')
			{
				mlx_put_image_to_window(window.mlx, window.win, land.img, j * 50, i * 50);
				mlx_put_image_to_window(window.mlx, window.win, player.img, j * 50, i * 50);
			}
			else if (map[i][j] == 'E')
			{
				mlx_put_image_to_window(window.mlx, window.win, land.img, j * 50, i * 50);
				mlx_put_image_to_window(window.mlx, window.win, enemy.img, j * 50, i * 50);
			}
			else if (map[i][j] == 'X')
			{
				mlx_put_image_to_window(window.mlx, window.win, land.img, j * 50, i * 50);
				mlx_put_image_to_window(window.mlx, window.win, exit.img, j * 50, i * 50);
			}
			else if (map[i][j] == 'C')
			{
				mlx_put_image_to_window(window.mlx, window.win, land.img, j * 50, i * 50);
				mlx_put_image_to_window(window.mlx, window.win, collect.img, j * 50, i * 50);
			}
			j++;
		}
		i++;
	}
	
	printf("%d\n", i);
	printf("%d\n", j);
	
	
	
	
	mlx_key_hook(window.win, key_hook, &window);
	mlx_loop(window.mlx);

	return 0;
}