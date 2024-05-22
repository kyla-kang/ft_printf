/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:00:39 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/14 14:19:05 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flag(const char **format, t_flag *flag)
{
	while (**format == '-' || **format == '0' || **format == '.' ||
			**format == '#' || **format == ' ' || **format == '+')
	{
		if (**format == '-')
			flag->flag_minus = 1;
		else if (**format == '0')
			flag->flag_zero = 1;
		else if (**format == '.')
			flag->flag_dot = 1;
		else if (**format == '#')
			flag->flag_hash = 1;
		else if (**format == ' ')
			flag->flag_space = 1;
		else if (**format == '+')
			flag->flag_plus = 1;
		(*format)++;
	}
}

void	parse_width(const char **format, va_list args, t_flag *flag)
{
	if (**format == '*')
	{
		flag->width = va_arg(args, int);
		(*format)++;
	}
	else
	{
		while (**format >= '0' && **format <= '9')
		{
			flag->width = flag->width * 10 + (**format - '0');
			(*format)++;
		}
	}
}

void	parse_precision(const char **format, va_list args, t_flag *flag)
{
	if (**format == '.')
	{
		flag->flag_dot = 1;
		(*format)++;
		if (**format == '*')
		{
			flag->precision = va_arg(args, int);
			(*format)++;
		}
		else
		{
			flag->precision = 0;
			while (**format >= '0' && **format <= '9')
			{
				flag->precision = flag->precision * 10 + (**format - '0');
				(*format)++;
			}
		}
	}
}

void	init_flag(t_flag *flag)
{
	flag->flag_minus = 0;
	flag->flag_zero = 0;
	flag->flag_dot = 0;
	flag->flag_hash = 0;
	flag->flag_space = 0;
	flag->flag_plus = 0;
	flag->width = 0;
	flag->precision = -1;
}
