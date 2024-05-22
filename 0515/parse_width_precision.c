/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width_precision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:47:45 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/21 15:56:39 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_width_precision(const char **format, t_format *fmt, va_list args)
{
	if (**format == '*')
	{
		fmt->width = va_arg(args, int);
		(*format)++;
	}
	else
	{
		while (**format >= '0' && **format <= '9')
			fmt->width = fmt->width * 10 + (*(*format)++ - '0');
	}
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
