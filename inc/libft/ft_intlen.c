/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 02:38:58 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/07/27 16:32:19 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description:
**     Count the number of digits in an integer.
** Return:
**     Returns the number of digits including '-' sign if negative number.
*/

#include "libft.h"

int	ft_intlen(int n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		counter++;
	while (n)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}
