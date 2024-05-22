/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:00:47 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/21 15:59:22 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_conversion(t_format *fmt, va_list args)
{
	if (fmt->specifier == 'c')
		return (print_char(fmt, args));
	else if (fmt->specifier == 's')
		return (print_str(fmt, args));
	else if (fmt->specifier == 'p')
		return (print_ptr(fmt, args));
	else if (fmt->specifier == 'd' || fmt->specifier == 'i')
		return (print_dec(fmt, args));
	else if (fmt->specifier == 'u')
		return (print_unbr(fmt, args));
	else if (fmt->specifier == 'x')
		return (print_hexa(fmt, args, 0));
	else if (fmt->specifier == 'X')
		return (print_hexa(fmt, args, 1));
	else if (fmt->specifier == '%')
		return (ft_putchar('%'));
	return (0);
}
