/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:43:08 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/22 20:51:41 by tehuanmelo       ###   ########.fr       */
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
