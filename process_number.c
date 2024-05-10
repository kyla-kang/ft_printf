/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:52:39 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/09 21:52:55 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	process_number(const char **str)
{
	int	num;

	num = 0;
	while (**str >= '0' && **str <= '9')
	{
		num = num * 10 + (**str - '0');
		(*str)++;
	}
	(*str)--;
	return (num);
}
