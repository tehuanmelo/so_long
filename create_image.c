/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:31:30 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/18 20:47:24 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image create_image(t_game *game, char type)
{
	t_image image;
	
	image.height = 50;
	image.width = 50;
	
	if (type == '0')
		image.path = LAND;
	else if (type == '1')
		image.path = WALL;
	else if (type == 'P')
		image.path = PLAYER;
	else if (type == 'E')
		image.path = EXIT;
	else if (type == 'C')
		image.path = COLLECT;
		
	image.img = mlx_xpm_file_to_image(game->mlx, image.path, &image.width, &image.height);

	return image;
}

void draw_image(t_game *game, char type, int x, int y)
{
    t_image image;
    image = create_image(game, type);
    mlx_put_image_to_window(game->mlx, game->win, image.img, x * 50, y * 50);
    
}