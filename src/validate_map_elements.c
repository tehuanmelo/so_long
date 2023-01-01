/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elements.element                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:43:08 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/30 23:35:20 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_player_exit_collects(char element)
{
	static int	exit;
	static int	player;
	static int	collects;

	if (element == 'P')
		player++;
	else if (element == 'E')
		exit++;
	else if (element == 'C')
		collects++;
	if (player == 1 && exit == 1 && collects > 0)
		return (1);
	else
		return (0);
}

int	check_map_char_struct(char **map)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C')
				return (0);
			else if (map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == 'C')
				flag = check_player_exit_collects(map[i][j]);
			j++;
		}
		i++;
	}
	if (flag)
		return (1);
	return (0);
}

int	validate_collects(char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				if (map[i + 1][j] != 'X' || map[i - 1][j] != 'X' || map[i][j
					+ 1] != 'X' || map[i][j - 1] != 'X')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
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
