#include <stdio.h>

/* Rewriting exercise 1-3 to use a function for conversion */

int conversion(int fahr);

int main(void)
{
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("  F     C\n\n");
	for (float fahr = 0; fahr <= upper; fahr = fahr + step)
		printf("%3.0f %6.1d\n", fahr, conversion(fahr));
	return 0;
}

int conversion(int fahr)
{
	return ((5.0 / 9.0) * (fahr - 32.0));
}
