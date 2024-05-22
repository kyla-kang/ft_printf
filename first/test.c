#include <stdio.h>

int	main(void)
{
	printf("nothing :|%d|\n", 42);
	printf("+/5       :|%+5d|\n", 42);
	printf("+/-/5     :|%+-5d|\n", 42);
	printf("+/0/5     :|%+05d|\n", 42);
	printf("+/space/5 :|%+ 5d|\n", 42);
	printf("+/#/5     :|%+#5x|\n", 42);
	printf("-/0/5     :|%-05d|\n", 42);
	printf("-/space/5 :|%- 5d|\n", 42);
	printf("-/#/5     :|%-#5x|\n", 42);
	printf("0/space/5 :|%0 5d|\n", 42);
	printf("0/#/5     :|%0#5x|\n", 42);
	printf("space/#/5 :|% #5x|\n", 42);
	printf("./5       :|%.5d|\n", 42);
	printf("+/./5     :|%+.5d|\n", 42);
	printf("+/-/./5   :|%+-.5d|\n", 42);
	printf(" /+/-/./5 :|% +-.5d|\n", 42);
	printf("#/5       :|%#5x|\n", 42);
	printf("#/./5     :|%#.5x|\n", 42);
	return (0);
}
