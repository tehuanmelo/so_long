/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:26:16 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/28 13:40:53 by tehuanmelo       ###   ########.fr       */
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

int	is_ber(char *file_name)
{
	char	*str;

	str = ft_strrchr(file_name, '.');
	if (ft_strlen(str) == 4)
	{
		if (!ft_strncmp(".ber", str, 4))
			return (1);
	}
	return (0);
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


