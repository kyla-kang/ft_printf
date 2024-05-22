/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:34:16 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/21 15:56:39 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_char(char c, t_option *opt)
{
	int	count;

	count = 0;
	if (opt->flag_minus)
		count += ft_putchar(c);
	while (opt->width-- > 1)
		count += ft_putchar(' ');
	if (!opt->flag_minus)
		count += ft_putchar(c);
	return (count);
}

int	ft_print_str(char *s, t_option *opt)
{
	int	count;

	if (!s)
		s = "(null)";
	count = 0;
	while (s[count] && (!opt->flag_dot || count < opt->precision))
		count++;
	if (opt->flag_minus)
		write(1, s, count);
	while (opt->width-- > count)
		count += ft_putchar(' ');
	if (!opt->flag_minus)
		write(1, s, count);
	return (count);
}

int	ft_print_nbr(int n, t_option *opt)
{

}
