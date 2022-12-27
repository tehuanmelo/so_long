/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:49:11 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/08/08 12:11:47 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, char x)
{
	int		counter;
	char	*str;

	str = "0123456789abcdef";
	counter = 0;
	if (x == 'X')
		str = "0123456789ABCDEF";
	if (n > 15)
	{
		counter += ft_puthex(n / 16, x);
		counter += ft_puthex(n % 16, x);
	}
	else
		counter += ft_putchar(str[n]);
	return (counter);
}
