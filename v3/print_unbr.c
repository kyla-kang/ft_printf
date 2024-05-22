/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:04:01 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/21 16:04:28 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_unbr(t_format *fmt, va_list args)
{
	unsigned int n;
	int count;

	n = va_arg(args, unsigned int);
	count = 0;
	if (n == 0 && fmt->dot && fmt->precision == 0)
		return (0);
	if (fmt->minus)
		count += ft_putunbr(n);
	while (fmt->width-- > ft_numlen(n))
	{
		if (fmt->zero && !fmt->minus)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
	}
	if (!fmt->minus)
		count += ft_putunbr(n);
	return (count);
}
