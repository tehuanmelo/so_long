/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:26:16 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/31 13:01:45 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber(char *file_name)
{
	char	*str;

	str = ft_strrchr(file_name, '.');
	if (!str)
		return (0);
	else if (ft_strlen(str) == 4)
	{
		if (!ft_strncmp(".ber", str, 4))
			return (1);
	}
	return (0);
}

char	*read_map(int fd)
{
	char			*buffer;
	static char		*str;
	ssize_t			flag;

	buffer = malloc((BUFFER_SIZE) * sizeof(char));
	if (!buffer)
		return (NULL);
	flag = 1;
	while (flag)
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		if (flag == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[flag] = 0;
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	count_collects(char **map)
{
	int	i;
	int	j;
	int	collects;

	collects = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				collects++;
			j++;
		}
		i++;
	}
	return (collects);
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
