/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:49:50 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/10 14:08:25 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>//for malloc & free
# include <stdarg.h>//for va_*
# include <unistd.h>//for write

typedef struct s_flag
{
	int	plus;
	int	minus;
	int	zero;
	int	space;
	int	hash;
	int	dot;
	int	min_width;
	int	precision;
}		t_flag;

//ft_printf
int		main(void);
int		ft_printf(const char *str, ...);

//parsing
void	init_flag(t_flag *flag);
void	process_flag(const char *p, t_flag *flag);
void	process_precision(const char **p, va_list *args, t_flag *flag);

int		process(const char **format, va_list *args, t_flag *flag);
int		process_number(const char **str);

//function for printing
int		print_char(char c);
int		print_str(char *str);
int		print_dec(long long num);
int		print_hexa(unsigned long long num, int uppercase);
int		print_ptr(void *pointer);

//etc
int		ft_atoi(const char *str);

#endif
