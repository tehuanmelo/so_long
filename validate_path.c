/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:43:08 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/22 21:08:25 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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