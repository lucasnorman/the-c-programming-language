#include <stdio.h>

int main(void)
{
	int c, spaced;

	spaced = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			if (spaced == 0)
			{
				spaced = 1;
				putchar(c);
			}
		}

		if (c != ' ')
		{
			spaced = 0;
			putchar(c);
		}
	}

	return 0;
}