/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:15:00 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/10 18:12:10 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	handle_flag(const char **format, va_list *args, t_flag *flag)
{
	const char	*p;

	p = *format;
	while (*p)
	{
		if (*p == '+' || *p == '-' || *p == '0' || *p == ' ' || *p == '#')
			flag_option(p, flag);
		else if (*p == '.')
			flag_precision(&p, args, flag);
		else if (*p >= '1' && *p <= '9')
			flag -> min_width = flag_number(&p);
		else
		{
			*format = p;
			return (1);
		}
		p++;
	}
	*format = p;
	return (1);
}
