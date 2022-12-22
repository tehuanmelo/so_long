/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:43:08 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/22 20:50:32 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	check_map_char_struct(char **map)
{
	int	i;
	int	j;
	int	exit;
	int	player;

	exit = 0;
	player = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C')
				return (0);
			else if (map[i][j] == 'P')
				player++;
			else if (map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit == 1 && player == 1)
		return (1);
	return (0);
}

int	validate_collects(char **map)
{
	int	i;
	int	j;
	int	collects;

	i = 1;
	collects = 0;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				if (map[i + 1][j] == 'X' || map[i - 1][j] == 'X' || map[i][j
					+ 1] == 'X' || map[i][j - 1] == 'X')
					collects++;
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (collects);
}

int	validate_exit(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				if (map[i + 1][j] == 'X' || map[i - 1][j] == 'X' || map[i][j
					+ 1] == 'X' || map[i][j - 1] == 'X')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

