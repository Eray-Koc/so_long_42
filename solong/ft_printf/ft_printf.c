/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erkoc <erkoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:56:18 by erkoc             #+#    #+#             */
/*   Updated: 2024/01/13 16:42:36 by erkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checker(char a)
{
	if (a == 'c' || a == 's' || a == 'd' || a == 'i' || a == 'u'
		|| a == 'x' || a == 'X' || a == 'p' || a == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *a, ...)
{
	va_list	args;
	int		i;
	int		size;

	va_start (args, a);
	i = 0;
	size = 0;
	while (a[i])
	{
		if (a[i] == '%' && ft_checker(a[i + 1]))
			size += func(a[++i], args);
		else if (a[i] == '%')
			size += ft_putstr("");
		else
			size += ft_putchr(a[i]);
		i++;
	}
	va_end(args);
	return (size);
}
