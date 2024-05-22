/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:06:26 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/14 14:12:33 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process(const char **format, va_list args, t_flag *flag)
{
	int	count;

	count = 0;
	init_flag(flag);
	parse_flag(format, flag);
	parse_width(format, args, flag);
	parse_precision(format, args, flag);
	if (**format == 'c')
		count += ft_print_char(va_arg(args, int), flag);
	else if (**format == 's')
		count += ft_print_str(va_arg(args, char *), flag);
	else if (**format == 'p')
		count += ft_print_ptr(va_arg(args, void *), flag);
	else if (**format == 'd' || **format == 'i')
		count += ft_print_nbr(va_arg(args, int), flag);
	else if (**format == 'u')
		count += ft_print_nbr_unsigned(va_arg(args, unsigned int), flag);
	else if (**format == 'x')
		count += ft_print_nbr_hexa(va_arg(args, unsigned int), 0, flag);
	else if (**format == 'X')
		count += ft_print_nbr_hexa(va_arg(args, unsigned int), 1, flag);
	else if (**format == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(**format);
	return (count);
}

/*
static int	specifier(const char **format, va_list args)
{
	int	count;

	count = 0;
	(*format)++;
	if (**format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (**format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (**format == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (**format == 'd' || **format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (**format == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (**format == 'x')
		count += ft_putnbr_hexa(va_arg(args, unsigned int), 0);
	else if (**format == 'X')
		count += ft_putnbr_hexa(va_arg(args, unsigned int), 1);
	else if (**format == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(**format);
	return (count);
}
*/
