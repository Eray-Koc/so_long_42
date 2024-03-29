/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erkoc <erkoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:19:50 by erkoc             #+#    #+#             */
/*   Updated: 2024/01/12 17:56:21 by erkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchr(char c);
int	ft_putstr(char *str);
int	ft_count_num(int n);
int	ft_hexaconverter_capital(unsigned int n);
int	ft_hexaconverter(unsigned int n);
int	ft_putnbr(int n);
int	ft_unsigned_int(unsigned int n);
int	ft_ptr(unsigned long n, int c);
int	func(char c, va_list args);
int	ft_printf(const char *a, ...);

#endif