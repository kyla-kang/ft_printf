/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:48:36 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/21 15:56:39 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_conversion(const char **format, va_list args, t_format *fmt)
{
	int	count;

	count = 0;
	if (**format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (**format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (**format == 'p')
		count += ft_putptr(va_arg(args, unsigned long long));
	else if (**format == 'd' || **format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (**format == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	else if (**format == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 0);
	else if (**format == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 1);
	else if (**format == '%')
		count += ft_putchar('%');
	return (count);
}
