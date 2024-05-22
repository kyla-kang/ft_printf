/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:36:46 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/14 14:33:24 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_option
{
	int	flag_minus;
	int	flag_zero;
	int	flag_dot;
	int	flag_hash;
	int	flag_space;
	int	flag_plus;
	int	width;
	int	precision;
}		t_option;

int	ft_printf(const char *format, ...);
int	handle_conversion(const char **format, va_list args, t_option *opt);
int	parse_flag(const char **format, t_option *opt);
int	parse_width(const char **format, va_list args, t_option *opt);
int	parse_precision(const char **format, va_list args, t_option *opt);

int	ft_putchar(char c);

int	ft_print_char(char c, t_option *opt);
int	ft_print_str(char *s, t_option *opt);
int	ft_print_nbr(int n, t_option *opt);
int	ft_print_unsigned(unsigned int n, t_option *opt);
int	ft_print_hexa(unsigned int n, int uppercase, t_option *opt);
int	ft_print_ptr(void *ptr, t_option *opt);

#endif
