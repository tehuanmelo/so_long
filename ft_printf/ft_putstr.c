/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:53:02 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/08/08 12:09:46 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	counter;

	counter = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
		counter += ft_putchar(*str++);
	return (counter);
}
