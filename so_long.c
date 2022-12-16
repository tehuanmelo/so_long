/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:05:47 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/16 17:26:58 by tde-melo         ###   ########.fr       */
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

t_image create_image(t_window window, char type, int x, int y)
{
	t_image image;
	
	image.height = 50;
	image.width = 50;
	image.position.x = x * 50;
	image.position.y = y * 50;
	
	if (type == '0')
		image.path = LAND;
	else if (type == '1')
		image.path = WALL;
	else if (type == 'E')
		image.path = ENEMY;
	else if (type == 'P')
		image.path = PLAYER;
	else if (type == 'X')
		image.path = EXIT;
	else if (type == 'C')
		image.path = COLLECT;
		
	image.img = mlx_xpm_file_to_image(window.mlx, image.path, &image.width, &image.height);

	return image;
}

void write_background(char **map, t_window window)
{
	int i, j;
	t_image image;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			image = create_image(window, '0', j, i);
			mlx_put_image_to_window(window.mlx, window.win, image.img, image.position.x, image.position.y);
			j++;
		}
		i++;
	}
}

void write_elements(char **map, t_window window)
{
	int i, j;
	t_image image;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			image = create_image(window, map[i][j], j, i);
			mlx_put_image_to_window(window.mlx, window.win, image.img, image.position.x, image.position.y);
			j++;
		}
		i++;
	}
}

void player_movement(char **map, t_window window)
{
	int i, j;
	t_image land;
	t_image player;

	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == 'P')
			{
				land = create_image(window, '0', j, i);
				player = create_image(window, 'P', j * 50, i);
				mlx_put_image_to_window(window.mlx, window.win, land.img, land.position.x, land.position.y);
				mlx_put_image_to_window(window.mlx, window.win, player.img, player.position.x, player.position.y);
			}
			j++;
		}
		i++;
	}
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
	

	t_window window;
	window.height = i * 50;
	window.width = j * 50;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, window.width, window.height, "So_long!");


	write_background(map, window);
	write_elements(map, window);
	
	mlx_key_hook(window.win, key_hook, &window);
	// mlx_loop_hook(window.mlx, update_screen, structhere);/
	mlx_loop(window.mlx);

	return 0;
}