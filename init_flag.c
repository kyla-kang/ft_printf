/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:55:31 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/09 21:13:30 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_flag(t_flag *flag) //t_flag 구조체를 초기화
{
	flag -> minus = 0;//'-' 플래그가 사용된 경우 minus 필드를 0으로 초기화
	flag -> plus = 0;//'+' 플래그가 사용된 경우 plus 필드를 0으로 초기화
	flag -> zero = 0;//공백 대신 '0'으로 패딩을 채울 것인지를 나타내는 '0' 플래그가 사용된 경우 zero 필드를 0으로 초기화
	flag -> space = 0;//' ' 플래그가 사용된 경우 space 필드를 0으로 초기화
	flag -> hash = 0;//'#' 플래그가 사용된 경우 sharp 필드를 0으로 초기화
	flag -> dot = 0;//'.' 플래그가 사용된 경우 필드 0으로 초기화. (정밀도 지정)
	flag -> min_width = 0;//출력할 최소 너비를 설정하기 위해 'min_w' 필드를 0으로 초기화
	flag -> precision = -1;//출력할 값의 정밀도를 설정하기 위해 'precision' 필드를 초기화. -1은 '정밀도 미설정'을 의미
}
