/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:10:27 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/10 18:11:01 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	main(void)
{
	char			*str;
	int				num;
	unsigned int	unum;
	void			*ptr;

	str = "Hello, world!";
	num = -42;
	unum = __INT_MAX__;
	ptr = &num;

	printf("printf for d: %05d\n", num);
	ft_printf("ft_printf for d: %05d\n\n", num);

	return (0);
}

/*
	printf("printf for char: %c\n", 'A');
	ft_printf("ft_printf for char: %c\n\n", 'A');

	printf("printf for percent: %c\n", '%');
	ft_printf("ft_printf for percent: %c\n\n", '%');

	printf("printf for str: %s\n", str);
	ft_printf("ft_printf for str: %s\n\n", str);

	printf("printf for ptr: %p\n", ptr);
	ft_printf("ft_printf for ptr: %p\n\n", ptr);

	printf("printf for d: %d\n", num);
	ft_printf("ft_printf for d: %d\n\n", num);

	printf("printf for i: %i\n", num);
	ft_printf("ft_printf for i: %i\n\n", num);

	printf("printf for u: %u\n", unum);
	ft_printf("ft_printf for u: %u\n\n", unum);

	printf("printf for x: %x\n", num);
	ft_printf("ft_printf for x: %x\n\n", num);

	printf("printf for X: %X\n", num);
	ft_printf("ft_printf for X: %X\n\n", num);
*/
