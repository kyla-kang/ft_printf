/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:40:07 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/10 14:47:37 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	handle_conversion(va_list *args, char spec)
{
	if (spec == 'c')
		return (print_char(va_arg(*args, int)));
	else if (spec == 's')
		return (print_str(va_arg(*args, char *)));
	else if (spec == 'p')
		return (print_ptr(va_arg(*args, void *)));
	else if (spec == 'd' || spec == 'i')
		return (print_dec(va_arg(*args, int)));
	else if (spec == 'u')
		return (print_dec((unsigned int)va_arg(*args, unsigned int)));
	else if (spec == 'x')
		return (print_hexa(va_arg(*args, unsigned int), 0));
	else if (spec == 'X')
		return (print_hexa(va_arg(*args, unsigned int), 1));
	else if (spec == '%')
		return (print_char('%'));
	return (0);
}

static int	handle_format(va_list *args, const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += handle_conversion(args, *str++);
		}
		else
		{
			write(1, str, 1);
			count++;
			str++;
		}
	}
	return (count);
}
/*
static int	handle_format(va_list *args, const char *str, t_flag *flag)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			init_flag(flag);
			count += handle_conversion(args, *str++);
		}
		else
		{
			write(1, str, 1);
			count++;
			str++;
		}
	}
	return (count);
}*/

int	ft_printf(const char *str, ...)
{
	va_list	args;
//	t_flag	flag;
	int		count;

	count = 0;
	va_start(args, str);
	count += handle_format(&args, str);
	va_end(args);
	return (count);
}
