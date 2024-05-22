/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:49:50 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/13 16:32:07 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>//for malloc & free
# include <stdarg.h>//for va_*
# include <unistd.h>//for write

//ft_printf
int		ft_printf(const char *str, ...);

//void	init_flag(t_flag *flag);

//int		handle_flag(const char **format, va_list *args, t_flag *flag);
//int		flag_number(const char **str);
//void	flag_option(const char *p, t_flag *flag);
//void	flag_precision(const char **p, va_list *args, t_flag *flag);

int		main(void);
int		process_specifier(va_list *args, char spec);
int		print_char(char c);
int		print_str(char *str);
int		print_dec(long long num);
int		print_hexa(unsigned long long num, int uppercase);
int		print_ptr(void *pointer);

//etc
int		ft_atoi(const char *str);

#endif

/*typedef struct s_flag
{
	int	plus;
	int	minus;
	int	zero;
	int	space;
	int	hash;
	int	dot;
	int	min_width;
	int	precision;
}		t_flag;*/
