#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int ret;
	int ft_ret;

	// Test %c
	printf("Testing %%c:\n");
	ret = printf("printf:    [%c]\n", 'A');
	ft_ret = ft_printf("ft_printf: [%c]\n", 'A');
	printf("printf ret: %d, ft_printf ret: %d\n\n", ret, ft_ret);

	// Test %s
	printf("Testing %%s:\n");
	ret = printf("printf:    [%s]\n", "Hello, world!");
	ft_ret = ft_printf("ft_printf: [%s]\n", "Hello, world!");
	printf("printf ret: %d, ft_printf ret: %d\n\n", ret, ft_ret);

	// Test %p
	printf("Testing %%p:\n");
	void *ptr = &ret;
	ret = printf("printf:    [%p]\n", ptr);
	ft_ret = ft_printf("ft_printf: [%p]\n", ptr);
	printf("printf ret: %d, ft_printf ret: %d\n\n", ret, ft_ret);

	// Test %d and %i
	printf("Testing %%d and %%i:\n");
	ret = printf("printf:    [%d] [%i]\n", 123, 456);
	ft_ret = ft_printf("ft_printf: [%d] [%i]\n", 123, 456);
	printf("printf ret: %d, ft_printf ret: %d\n\n", ret, ft_ret);

	// Test %u
	printf("Testing %%u:\n");
	ret = printf("printf:    [%u]\n", 123456789);
	ft_ret = ft_printf("ft_printf: [%u]\n", 123456789);
	printf("printf ret: %d, ft_printf ret: %d\n\n", ret, ft_ret);

	// Test %x and %X
	printf("Testing %%x and %%X:\n");
	ret = printf("printf:    [%x] [%X]\n", 255, 255);
	ft_ret = ft_printf("ft_printf: [%x] [%X]\n", 255, 255);
	printf("printf ret: %d, ft_printf ret: %d\n\n", ret, ft_ret);

	// Test %%
	printf("Testing %%%%:\n");
	ret = printf("printf:    [%%]\n");
	ft_ret = ft_printf("ft_printf: [%%]\n");
	printf("printf ret: %d, ft_printf ret: %d\n\n", ret, ft_ret);

	// Test with width and precision
	printf("Testing width and precision:\n");
	ret = printf("printf:    [%10d] [%10.5d]\n", 42, 42);
	ft_ret = ft_printf("ft_printf: [%10d] [%10.5d]\n", 42, 42);
	printf("printf ret: %d, ft_printf ret: %d\n\n", ret, ft_ret);

	// Test with flags
	printf("Testing flags:\n");
	ret = printf("printf:    [%-10d] [%010d] [%+d] [% d] [%#x]\n", 42, 42, 42, 42, 42);
	ft_ret = ft_printf("ft_printf: [%-10d] [%010d] [%+d] [% d] [%#x]\n", 42, 42, 42, 42, 42);
	printf("printf ret: %d, ft_printf ret: %d\n\n", ret, ft_ret);

	return 0;
}
