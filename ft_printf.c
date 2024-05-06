/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:40:07 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/06 17:13:25 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	process_flags(t_list *list, const char *str, int *i)
{
	if (str[1] == '0')
	{
		list->zero_offset = ft_atoi(str + 2);
		list -> zero = 1;
	}
	else if (str[1] == ' ')
		list -> space = 1;
	else if (str[1] == '+')
		list -> plus = 1;
	else if (str[1] == '-')
	{
		list -> offset = ft_atoi();
		list -> minus = 1;
	}
	else if (str[1] == '.')
	{
		list -> precision = ft_atoi();
		list -> dot = 1;
	}
	else if (str[1] == '#')
		list -> sharp = 1;
}

int	process(const char *str, va_list *param, int *i)
{
	int		total;
	t_list	list;

	total = 0;
	init_list(&list);
	while (in_set(str[*i + 1], "0123456789 +-.#"))
	{
		if (in_set(str[*i + 1]), " +-.#")
			process_flags(&list, str + *i, i);
		else
		{
			list.minimum_width = ft_atoi(str + *i + 1);
			*i--;
		}
		*i++;
	}
	total += process_normal(str + *i, param, list);
	*i++;
	return (total);
}

int	ft_printf(const char *str, ...)
{
	va_list	param;
	int		i;
	int		total;

	i = 0;
	total = 0;
	va_start (param, str);
	while (str[i])
	{
		if (str[i] == '%')
			total += process(str, &param, &i);
		else
			total += putchar(str[i]);
	}
	va_end(param);
	return (total);
}
