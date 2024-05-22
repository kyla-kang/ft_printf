/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:01:27 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/21 15:56:39 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(t_format *fmt, va_list args)
{
	unsigned long long ptr;
	int count;
	int len;

	ptr = (unsigned long long)va_arg(args, void *);
	count = 0;
	len = 2 + ft_putptr(ptr); // 2 for "0x"
	if (fmt->minus)
	{
		count += ft_putstr("0x");
		count += ft_putptr(ptr);
	}
	while (fmt->width-- > len)
		count += ft_putchar(' ');
	if (!fmt->minus)
	{
		count += ft_putstr("0x");
		count += ft_putptr(ptr);
	}
	return (count);
}

/*
int	print_ptr(t_format *fmt, va_list args)
{
	unsigned long long ptr;
	int count;
	int len;

	ptr = (unsigned long long)va_arg(args, void *);
	count = 0;
	len = 2;
	len += ft_putptr(ptr);
	if (fmt->minus)
		count += ft_putstr("0x");
	count += ft_putptr(ptr);
	while (fmt->width-- > len)
		count += ft_putchar(' ');
	if (!fmt->minus)
		count += ft_putstr("0x");
	return (count);
}
*/
