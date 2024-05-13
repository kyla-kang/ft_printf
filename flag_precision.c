/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:53:08 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/09 21:53:13 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	process_precision(const char **p, va_list *args, t_flag *flag)
{
	flag -> dot = 1;
	(*p)++;
	if (**p == '*')
	{
		flag -> precision = va_arg(*args, int);
		(*p)++;
	}
	else
		flag -> precision = process_number(p);
}
