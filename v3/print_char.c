/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:01:01 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/22 13:29:10 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(t_format *fmt, va_list args)
{
	char c;
	int count;

	count = 0;
	c = (char)va_arg(args, int);
	if (fmt->minus)
		count += ft_putchar(c);
	while (fmt->width-- > 1)
		count += ft_putchar(' ');
	if (!fmt->minus)
		count += ft_putchar(c);
	return (count);
}
