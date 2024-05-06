/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:49:50 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/06 16:51:55 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>//for va_*
# include <unistd.h>//for write
# include <stdlib.h>//for malloc&free

typedef struct s_list
{
	int	sharp;
	int	space;
	int	plus;
	int	minus;
	int	minimum_width;
	int	dot;
	int	precision;
	int	offset;
	int	zero;
	int	zero_offset;
}		t_list;

int	ft_printf(const char *str, ...);

int	ft_strlen(char *str);
int	ft_atoi(const char *str);

int	ft_putchar(char c, t_list list);
int	ft_putstr(char *str, t_list list);
int	ft_putnum(long lng, t_list list);
int	ft_putptr(void *ptr, t_list list);
int	ft_putnum_u(unsigned long lng, t_list list);
int	ft_putnum_b(int num, int is_maj, t_list list);

int	print_char(char c);

#endif