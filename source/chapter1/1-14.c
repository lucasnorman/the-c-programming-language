#include <stdio.h>

/* 
 * Vertical solution again. Less comments because many things are the same as the last problem.
 * The answer styling is not perfect, but that is ok.
 */

/* For the original ASCII character set */
#define CHARS 128

int main(void)
{
	int c, big, counter;
	long unique[CHARS];

	counter = big = 0;

	for (int init = 0; init < CHARS; init++)
	{
		unique[init] = 0;
	}
	while((c = getchar()) != EOF)
	{
		if (c < CHARS)
			++unique[c];
	}
	printf("\n\n\n");
	/* Get the largest number on the y-axis */
	for (int i = 0; i < CHARS; i++)
	{
		if (big < unique[i])
			big = unique[i];
	}
	for (int j = 0; j < big; j++)
	{
		printf("%3.0d |", big - j);
		for (int k = 0; k < CHARS; k++)
		{
			if (k != CHARS - 1)
			{
				if (unique[k] > 0)
				{
					if (unique[k] >= big - j)
						printf(" *  ");
					else
						printf("    ");
				}
			}
			else if (k == CHARS - 1)
			{
				if (unique[k] >= big - j)
					printf(" * \n");
				else
					printf(" \n");
			}
		}
	}
	for (int l = 0; l < CHARS; l++)
	{
		if (l == 0)
			printf("    +---");
		else
		{
			if (unique[l] != 0)
				printf("----");
		}
	}
	printf("\n");
	for (int m = 0; m < CHARS; m++)
	{
		/* Start off the numbers */
		if (unique[m] > 0 && counter == 0)
		{
			printf("      %d", m);
			++counter;
		}
		else
		{
			if (unique[m] != 0)
				printf(" %d", m);
		}
	}
	return 0;
}