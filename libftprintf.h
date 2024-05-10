/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:49:50 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/09 22:47:43 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H //'LIBFFTPRINTF_H'라는 매크로가 정의되어 있지 않은 경우에만 다음 코드를 포함하도록 하는 전처리 지시문. 헤더파일이 중복으로 포함되는 것을 방지한다.
#define LIBFTPRINTF_H //매크로 정의

#include <stdarg.h>//for va_*
#include <unistd.h>//for write

typedef struct s_flag //'t_flag' 이라는 이름의 구조체 타입을 정의. ft_printf 함수의 포맷팅 옵션을 저장하고 플래그를 관리한다.
{
	int	plus; //'+'
	int	minus; //'-'
	int	zero; //'0'
	int	space; //' '
	int	hash; //'#'
	int	dot; //'.'
	int	min_width; //최소 너비
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

#endif // 'LIBFTPRINTF_H' 조건부 컴파일 블록을 종료한다.
