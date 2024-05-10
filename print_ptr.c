/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:34:43 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/09 20:41:57 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_ptr(void *pointer)
{
	unsigned long long	address;
	char				buffer[65];
	char				*digit;
	char				*ptr;

	address = (unsigned long long)pointer;
	digit = "0123456789abcdef";
	ptr = buffer + 64;
	*ptr = '\0';
	if (address == 0)
		return (print_str("0x0"));
	while (address != 0)
	{
		*(--ptr) = digit[address % 16];
		address /= 16;
	}
	*(--ptr) = 'x';
	*(--ptr) = '0';
	return (print_str(ptr));
}
