/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:52:25 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/10 18:04:11 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	flag_option(const char *p, t_flag *flag)
{
	if (*p == '+')
		flag -> plus = 1;
	else if (*p == '-')
		flag -> minus = 1;
	else if (*p == '0')
		flag -> zero = 1;
	else if (*p == ' ')
		flag -> space = 1;
	else if (*p == '#')
		flag -> hash = 1;
}
