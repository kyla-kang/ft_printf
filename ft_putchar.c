/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:24:48 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/06 16:30:52 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_putchar(char c, t_list list)
{
	int	i;

	i = 0;
	while (i + 1 < list.minimum_width)
		i += print_char(' ');
	i += print_char(c);
	while (i < list.offset)
		i += print_char (' ');
	return (i);
}
