/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:50:04 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/21 15:56:39 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int uppercase)
{
	char	buffer[65];
	char	*digit;
	char	*ptr;

	if (uppercase)
		digit = "0123456789ABCDEF";
	else
		digit = "0123456789abcdef";
	ptr = buffer + 64;
	*ptr = '\0';
	if (n == 0)
		*(--ptr) = '0';
	else
	{
		while (n > 0)
		{
			*(--ptr) = digit[n % 16];
			n /= 16;
		}
	}
	return (ft_putstr(ptr));
}
