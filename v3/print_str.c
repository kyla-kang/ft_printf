/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:01:17 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/21 15:56:39 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnstr(char *str, int n)
{
	int count;

	count = 0;
	while (*str && n--)
		count += ft_putchar(*str++);
	return (count);
}

int	print_str(t_format *fmt, va_list args)
{
	char	*str;
	int		len;
	int		count;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = 0;
	while (str[len])
		len++;
	if (fmt->dot && fmt->precision < len)
		len = fmt->precision;
	count = 0;
	if (fmt->minus)
		count += ft_putnstr(str, len);
	while (fmt->width-- > len)
	{
		if (fmt->zero)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
	}
	if (!fmt->minus)
		count += ft_putnstr(str, len);
	return (count);
}

/*
int	print_str(t_format *fmt, va_list args)
{
	char	*str;
	int		len;
	int		count;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = 0;
	while (str[len])
		len++;
	if (fmt->dot && fmt->precision < len)
		len = fmt->precision;
	count = 0;
	if (fmt->minus)
		count += ft_putnstr(str, len);
	while (fmt->width-- > len)
		count += ft_putchar(' ');
	if (!fmt->minus)
		count += ft_putnstr(str, len);
	return (count);
}
*/
