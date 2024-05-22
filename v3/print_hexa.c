/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:02:03 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/21 15:59:22 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// print_prefix 함수 선언 추가
static void	print_prefix(t_format *fmt, int num, int *count, int uppercase);

int ft_hexlen(unsigned int num)
{
	int len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

static void	print_padding_hexa(int padding, int zero_flag)
{
	while (padding-- > 0)
	{
		if (zero_flag)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
}

static void	print_prefix(t_format *fmt, int num, int *count, int uppercase)
{
	if (fmt->hash && num != 0)
	{
		if (uppercase)
			*count += ft_putstr("0X");
		else
			*count += ft_putstr("0x");
	}
}

int print_hexa(t_format *fmt, va_list args, int uppercase)
{
	unsigned int num;
	int count;
	int len;
	int padding;

	num = va_arg(args, unsigned int);
	count = 0;
	len = ft_hexlen(num);
	if (num == 0 && fmt->dot && fmt->precision == 0)
		len = 0;
	padding = fmt->width - len;
	if (fmt->hash && num != 0)
		padding -= 2;
	if (fmt->minus)
	{
		print_prefix(fmt, num, &count, uppercase);
		count += ft_puthex(num, uppercase);
	}
	print_padding_hexa(padding, fmt->zero && !fmt->minus);
	if (!fmt->minus)
	{
		print_prefix(fmt, num, &count, uppercase);
		count += ft_puthex(num, uppercase);
	}
	return (count);
}

/*
int print_hexa(t_format *fmt, va_list args, int uppercase)
{
	unsigned int num;
	int count;
	int len;

	num = va_arg(args, unsigned int);
	count = 0;
	len = ft_hexlen(num);
	if (num == 0 && fmt->dot && fmt->precision == 0)
		len = 0;
	if (fmt->minus)
		count += ft_puthex(num, uppercase);
	while (fmt->width-- > len)
		count += ft_putchar(' ');
	if (!fmt->minus)
		count += ft_puthex(num, uppercase);
	return (count);
}
*/
