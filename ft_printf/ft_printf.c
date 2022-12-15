/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:09:28 by tehuanmelo        #+#    #+#             */
/*   Updated: 2022/08/08 12:22:20 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flag(const char fmt, va_list ap)
{
	int	print_len;

	print_len = 0;
	if (fmt == 'c')
		print_len += ft_putchar(va_arg(ap, int));
	else if (fmt == 's')
		print_len += ft_putstr(va_arg(ap, char *));
	else if (fmt == 'i' || fmt == 'd')
		print_len += ft_putnbr(va_arg(ap, int));
	else if (fmt == 'u')
		print_len += ft_putnbr(va_arg(ap, unsigned int));
	else if (fmt == 'x' || fmt == 'X')
		print_len += ft_puthex(va_arg(ap, unsigned int), fmt);
	else if (fmt == 'p')
	{
		print_len += ft_putstr("0x");
		print_len += ft_puthex(va_arg(ap, unsigned long int), fmt);
	}
	return (print_len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		print_len;

	va_start(ap, fmt);
	print_len = 0;
	while (*fmt)
	{
		if (*fmt == '%' && (*(fmt + 1)) == '%')
		{
			print_len += ft_putchar('%');
			fmt++;
		}
		else if (*fmt == '%')
		{
			fmt++;
			print_len += check_flag(*fmt, ap);
		}
		else
			print_len += ft_putchar(*fmt);
		fmt++;
	}
	va_end(ap);
	return (print_len);
}
