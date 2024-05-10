/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:55:31 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/10 13:16:57 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_flag(t_flag *flag)
{
	flag -> minus = 0;
	flag -> plus = 0;
	flag -> zero = 0;
	flag -> space = 0;
	flag -> hash = 0;
	flag -> dot = 0;
	flag -> min_width = 0;
	flag -> precision = -1;
}
