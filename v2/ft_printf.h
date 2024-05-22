/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:35:40 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/21 15:56:39 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>//for va_*
# include <unistd.h>//for write

typedef struct s_format
{
	int		minus;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		precision;
	char	specifier;
}	t_format;

int		ft_printf(const char *str, ...);

int		print_char(char c);
int		print_str(char *str);
int		print_ptr(void *pointer);
int		print_dec(long long num);
int		print_hexa(unsigned long long num, int uppercase);
int		process_specifier(va_list *args, char spec);

void	init_format(t_format *fmt);
void	set_flag(const char **format, t_format *fmt);
void	parse_width_precision(const char **format, t_format *fmt, va_list args);

#endif
