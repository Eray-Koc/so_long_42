/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcz.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erkoc <erkoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:48:05 by erkoc             #+#    #+#             */
/*   Updated: 2024/01/13 15:09:18 by erkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexaconverter(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n >= 16)
		ret += ft_hexaconverter(n / 16);
	ret += write(1, &"0123456789abcdef"[n % 16], 1);
	return (ret);
}

int	ft_putnbr(int n)
{
	int	len;

	len = ft_count_num(n);
	if (n == -2147483648)
	{
		return (ft_putstr("-2147483648"));
	}
	if (n < 0)
	{
		ft_putchr('-');
		n = n * (-1);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	if (n < 10)
	{
		ft_putchr((n + '0'));
	}
	return (len);
}

int	ft_ptr(unsigned long n, int c)
{
	int	x;

	x = 0;
	if (c == 1)
		x += ft_putstr("0x");
	if (n >= 16)
		x += ft_ptr(n / 16, 0);
	x += ft_putchr("0123456789abcdef"[n % 16]);
	return (x);
}

int	ft_putuns(unsigned int n)
{
	int	x;

	x = 0;
	if (n >= 10)
	{
		x += ft_putuns(n / 10);
		n = n % 10;
	}
	if (n < 10)
	{
		x += ft_putchr((n + '0'));
	}
	return (x);
}

int	func(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchr(va_arg(args, int)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'x')
		return (ft_hexaconverter(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_hexaconverter_capital(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_ptr(va_arg(args, unsigned long), 1));
	else if (c == '%')
		return (ft_putchr('%'));
	else if (c == 'u')
		return (ft_putuns(va_arg(args, unsigned int)));
	return (0);
}
