/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:50:16 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/06 16:51:41 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	num;
	unsigned long	max_int;

	i = 0;
	sign = 1;
	num = 0;
	max_int = 2147483647;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num > max_int)
			return (-1);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * (int)num);
}
