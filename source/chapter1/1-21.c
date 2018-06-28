#include <stdio.h>
#define TABSIZE 4

int main(void)
{
	int c, i, space;

	i = space = 0;

	while((c=getchar()) != EOF)
	{
		if (c == ' ')
		{
			++space;
			++i;	
		} 
		if (c == '\t')
		{
			if (i == 0 || (i % TABSIZE) == 0)
			{
				for (int j = 0; j < TABSIZE; ++j)
				{
					++space;
					++i;
				}
			}
			else
			{
				while((i % TABSIZE) != 0)
				{
					++space;
					++i;
				}
			}
		}
		else
		{
			if (space > 0)
			{
				for (int k = 0; k < space; ++k)
				{
					putchar(' ');
				}
			}
			space = 0;
			putchar(c);
			++i;
		}
	}
	return 0;
}
