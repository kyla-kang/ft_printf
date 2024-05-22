/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:34:38 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/21 15:56:39 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;
	int			i;
	t_format	*fmt;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			init_format(&fmt);
			set_flag(&format, &fmt);
			parse_width_prec(&format, &fmt, args);
			count += process_specifier(&args, format[i + 1]);
			i++;
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}

/*
	if (*format == '%')
		{
			format++;
			init_format(&fmt);
			set_flag(&format, &fmt);
			parse_width_prec(&format, &fmt, args);
			count += handle_conversion(&format, args, &fmt);
*/
