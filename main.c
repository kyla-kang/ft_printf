/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyukang <kyukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:10:27 by kyukang           #+#    #+#             */
/*   Updated: 2024/05/09 22:46:00 by kyukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>  // Include for printf function to compare output
#include "libftprintf.h"  // Your header file for ft_printf

int main(void)
{
	char *str = "Hello, world!";
	int num = -42;
	unsigned int unum = 42;
	void *ptr = &num;

	// Testing %c
	printf("%c\n", 'A');
	ft_printf("%c\n", 'A');

	// Testing %s
	printf("%s\n", str);
	ft_printf("%s\n", str);

	// Testing %p
	printf("%p\n", ptr);
	ft_printf("%p\n", ptr);

	// Testing %d and %i
	printf("%d %i\n", num, num);
	ft_printf("%d %i\n", num, num);

	// Testing %u
	printf("%u\n", unum);
	ft_printf("%u\n", unum);

	// Testing %x
	printf("%x\n", unum);
	ft_printf("%x\n", unum);

	// Testing %X
	printf("%X\n", unum);
	ft_printf("%X\n", unum);

	// Testing %%
	printf("%%\n");
	ft_printf("%%\n");

	return 0;
}
