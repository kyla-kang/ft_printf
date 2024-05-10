/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:20:46 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/09 17:03:20 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_dec(long long num)
{
	char	buffer[65];
	char	*ptr;
	int		neg;

	ptr = buffer + 64;
	neg = 0;
	if (num == 0)
		*(--ptr) = '0';
	else
	{
		if (num < 0)
		{
			neg = 1;
			num = -num;
		}
		while (num > 0)
		{
			*(--ptr) = (num % 10) + '0';
			num /= 10;
		}
		if (neg)
			*(--ptr) = '-';
	}
	return (print_str(ptr));
}
