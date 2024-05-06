/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:55:31 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/06 17:59:16 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_list(t_list *list)
{
	list -> sharp = 0; //
	list -> space = 0;
	list -> plus = 0;
	list -> minus = 0;
	list -> minimum_width = 0;
	list -> dot = 0;
	list -> precision = 0;
	list -> zero = 0;
	list -> zero_offset = 0;
	list -> offset = 0;
}
