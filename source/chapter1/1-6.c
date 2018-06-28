#include <stdio.h>

int main(void)
{
	printf("Press the ENTER key. Otherwise, press control-D to signal EOF.\n");
	printf("The expression getchar() != EOF evaluates to %d\n", getchar() != EOF);
	return 0;
}