#include <stdio.h>
#define TABSIZE 4

int main(void)
{
	int c, i;

	i = 0;

	while((c=getchar()) != EOF)
	{
		if (c == '\n')
		{
			i = 0;
		}
		if (c == '\t')
		{
			while((i % TABSIZE) != 0)
			{
				putchar(' ');
				++i;
			}
		}
		else 
		{
			putchar(c);
			++i;
		}
	}

	return 0;
}