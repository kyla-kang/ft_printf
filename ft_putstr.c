/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:31:03 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/06 16:37:38 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_strlen(char *str, int size)
{
	int	i;

	if (size == -1)
		return (print_str(str));
	i = 0;
	while (str[i] && i < size)
		write(1, &str[i++], 1);
	return (i);
}

int	ft_putstr(char *str, t_list list)
{
	int	i;
	int	len;

	i = 0;
	if (!str)
		len = 6;
	else
		len = ft_strlen(str);
	while (i + len < list.minimum_width)
		i += print_char(' ');
	if (!list.dot)
		list.precision = -1;
	if (!str)
		i += print_strlen("(null)", list.precision);
	else
		i += print_strlen(str, list.precision);
	while (i < list.offset)
		i += print_char(' ');
	return (i);
}
