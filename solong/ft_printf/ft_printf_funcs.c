/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erkoc <erkoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:20:56 by erkoc             #+#    #+#             */
/*   Updated: 2024/01/12 15:23:25 by erkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_count_num(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	else if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_hexaconverter_capital(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n >= 16)
		ret += ft_hexaconverter_capital(n / 16);
	ret += write(1, &"0123456789ABCDEF"[n % 16], 1);
	return (ret);
}
