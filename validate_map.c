/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:43:08 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/19 00:13:33 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_retangular(char **map)
{
    int i;
    int first_line;

    i = 0;
    first_line = ft_strlen(map[i]);
    while (map[i])
    {
        if ((int)ft_strlen(map[i]) != first_line)
        {
            ft_printf("Error! The map is not retangular!");
            return 0;
        }
        i++;
    }
    return 1;
}

int validate_map(char **map)
{
    if (is_retangular(map))
        return 1;

    return 0;
}