/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:01:17 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/10 18:01:35 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	handle_conversion(va_list *args, char spec)
{
	if (spec == 'c')
		return (print_char(va_arg(*args, int)));
	else if (spec == 's')
		return (print_str(va_arg(*args, char *)));
	else if (spec == 'p')
		return (print_ptr(va_arg(*args, void *)));
	else if (spec == 'd' || spec == 'i')
		return (print_dec(va_arg(*args, int)));
	else if (spec == 'u')
		return (print_dec((unsigned int)va_arg(*args, unsigned int)));
	else if (spec == 'x')
		return (print_hexa(va_arg(*args, unsigned int), 0));
	else if (spec == 'X')
		return (print_hexa(va_arg(*args, unsigned int), 1));
	else if (spec == '%')
		return (print_char('%'));
	return (0);
}
