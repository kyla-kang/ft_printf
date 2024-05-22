/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:59:55 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/21 16:11:30 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_format
{
	int		minus;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		precision;
	char	specifier;
}	t_format;

int ft_printf(const char *format, ...);

int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putnbr(int n);
int ft_putunbr(unsigned int n);
int ft_puthex(unsigned int n, int uppercase);
int ft_putptr(unsigned long long ptr);

int handle_conversion(t_format *fmt, va_list args);

int print_char(t_format *fmt, va_list args);
int print_str(t_format *fmt, va_list args);
int print_ptr(t_format *fmt, va_list args);
int print_dec(t_format *fmt, va_list args);
int print_hexa(t_format *fmt, va_list args, int uppercase);
int print_unbr(t_format *fmt, va_list args);

int ft_numlen(int num);

#endif
