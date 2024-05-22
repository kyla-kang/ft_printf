/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:39:44 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/13 17:53:00 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_dec(long long num)
{
	long long	n;
	int			len;

	n = num;
	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		len += print_dec(n / 10);
		len += print_dec(n % 10);
	}
	if (n < 10)
		len += print_char(n + 48);
	return (len);
}

/*
int	print_dec(long long num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		print_char('-');
		num = -num;
		count++;
	}
	if (num >= 10)
		print_dec(num / 10);
	print_char(num % 10 + '0');
	count++;
	return (count);
}
*/
