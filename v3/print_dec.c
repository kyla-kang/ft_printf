/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:01:48 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/21 15:56:39 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(int num)
{
	int len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = -num;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static void	print_padding(int padding, int zero_flag)
{
	while (padding-- > 0)
	{
		if (zero_flag)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
}

static void	print_sign(t_format *fmt, int num, int *count)
{
	if (num < 0)
		*count += ft_putchar('-');
	else if (fmt->plus)
		*count += ft_putchar('+');
	else if (fmt->space)
		*count += ft_putchar(' ');
}

int	print_dec(t_format *fmt, va_list args)
{
	int num;
	int count;
	int len;
	int padding;

	num = va_arg(args, int);
	count = 0;
	len = ft_numlen(num);
	if (num == 0 && fmt->dot && fmt->precision == 0)
		len = 0;
	padding = fmt->width - len;
	if (num < 0 || fmt->plus || fmt->space)
		padding--;
	if (fmt->minus)
	{
		print_sign(fmt, num, &count);
		count += ft_putnbr(num);
	}
	print_padding(padding, fmt->zero && !fmt->minus);
	if (!fmt->minus)
	{
		print_sign(fmt, num, &count);
		count += ft_putnbr(num);
	}
	return (count);
}

/*
int	print_dec(t_format *fmt, va_list args)
{
	int num;
	int count;
	int len;

	num = va_arg(args, int);
	count = 0;
	len = ft_numlen(num);
	if (num == 0 && fmt->dot && fmt->precision == 0)
		len = 0;
	if (fmt->minus)
		count += ft_putnbr(num);
	while (fmt->width-- > len)
		count += ft_putchar(' ');
	if (!fmt->minus)
		count += ft_putnbr(num);
	return (count);
}*/
