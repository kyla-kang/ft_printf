/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:00:24 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/22 13:45:13 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_format(t_format *fmt)
{
	fmt->minus = 0;
	fmt->zero = 0;
	fmt->dot = 0;
	fmt->hash = 0;
	fmt->space = 0;
	fmt->plus = 0;
	fmt->width = 0;
	fmt->precision = -1;
	fmt->specifier = '\0';
}

static void	parse_flag(const char **format, t_format *fmt)
{
	while (**format == '-' || **format == '0' || **format == ' ' ||
		**format == '#' || **format == '+')
	{
		if (**format == '-')
			fmt->minus = 1;
		else if (**format == '0')
			fmt->zero = 1;
		else if (**format == ' ')
			fmt->space = 1;
		else if (**format == '#')
			fmt->hash = 1;
		else if (**format == '+')
			fmt->plus = 1;
		(*format)++;
	}
}

static void	parse_width(const char **format, t_format *fmt, va_list args)
{
	if (**format == '*')
	{
		fmt->width = va_arg(args, int);
		if (fmt->width < 0)
		{
			fmt->minus = 1;
			fmt->width = -fmt->width;
		}
		(*format)++;
	}
	else
	{
		while (**format >= '0' && **format <= '9')
		{
			fmt->width = (fmt->width * 10) + (*(*format++) - '0');
		}
	}
}

static void	parse_precision(const char **format, t_format *fmt, va_list args)
{
	if (**format == '.')
	{
		fmt->dot = 1;
		(*format)++;
		if (**format == '*')
		{
			fmt->precision = va_arg(args, int);
			(*format)++;
		}
		else
		{
			fmt->precision = 0;
			while (**format >= '0' && **format <= '9')
				fmt->precision = fmt->precision * 10 + (*(*format)++ - '0');
		}
	}
}

static void	parse_specifier(const char **format, t_format *fmt)
{
	if (**format == 'c' || **format == 's' || **format == 'p' ||
		**format == 'd' || **format == 'i' || **format == 'u' ||
		**format == 'x' || **format == 'X' || **format == '%')
	{
		fmt->specifier = **format;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;
	t_format	fmt;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			init_format(&fmt);
			parse_flag(&format, &fmt);
			parse_width(&format, &fmt, args);
			parse_precision(&format, &fmt, args);
			parse_specifier(&format, &fmt);
			count += handle_conversion(&fmt, args);
		}
		else
			count += ft_putchar(*format++);
	}
	va_end(args);
	return (count);
}
