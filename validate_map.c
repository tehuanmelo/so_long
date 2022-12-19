/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:43:08 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/12/19 17:32:02 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_retangular(char **map)
{
    int i;
    int first_line;

    i = 0;
    first_line = (int)ft_strlen(map[i]);
    while (map[i])
    {
        if ((int)ft_strlen(map[i]) != first_line)
        {
            ft_printf("Error! The map is not retangular!");
            return 0;
        }
        i++;
    }
    if (i == first_line)
    {
        ft_printf("Error! The map is not retangular!");
        return 0;
    }
    return 1;
}

int have_walls(char **map)
{
    int i;
    int j;
    int last_col;

    last_col = (int)ft_strlen(map[0]) - 1;
    i = 0;
    while (map[i])
    {
        j = 0;
        if (map[i][j] != '1' || map[i][last_col] != '1')
            return 0;
        i++;
    }

    return 1;
}

int validate_map(char **map)
{
    if (is_retangular(map))
    {
        if (have_walls(map))
            return 1;
    }

    return 0;
}