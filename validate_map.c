/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:43:08 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/22 17:52:43 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(char **map)
{
	int	i;
	int	first_line;

	i = 0;
	first_line = (int)ft_strlen(map[i]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != first_line)
			return (0);
		i++;
	}
	if (i == first_line)
		return (0);
	return (1);
}

int	check_walls(char **map)
{
	int	i;
	int	j;
	int	last_col;

	last_col = (int)ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][last_col - 1] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

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

int	mark_path(char **map, int i, int j)
{
	map[i][j] = 'X';
	return (1);
}

int	check_path(char **map, int i, int j)
{
	if (map[i][j] == 'P')
		return (mark_path(map, i, j));
	else if (map[i][j] == 'X')
	{
		if (map[i + 1][j] == '0')
			return (mark_path(map, i + 1, j));
		else if (map[i - 1][j] == '0')
			return mark_path(map, i - 1, j);
		else if (map[i][j + 1] == '0')
			return mark_path(map, i, j + 1);
		else if (map[i][j - 1] == '0')
			return mark_path(map, i, j - 1);
	}
	return 0;
}

int	validate_path(char **map)
{
	int	i;
	int	j;
	int	flag;

	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 1;
		while (map[i])
		{
			j = 1;
			while (map[i][j])
			{
				flag = flag || check_path(map, i, j);
				j++;
			}
			i++;
		}
	}
	if (validate_exit(map))
		return 1;
	return 0;
}

int	validate_map(char **map)
{
	if (is_rectangular(map) && check_map_char_struct(map) && check_walls(map)
		&& validate_path(map) && validate_collects(map))
		return 1;
	else
	{
		ft_printf("Error\nCheck the map configuration");
		return 0;
	}
}