#include <stdio.h>

/* Vertical histogram */

/* I am going to make the max amount of words to be 10 to keep things simple */
#define MAXWORDS 10

int main(void)
{
	int c;
	int currwordlen, bigwordlen, numwords;
	long wordlens[MAXWORDS];

	numwords = bigwordlen = currwordlen = 0;

	/* Initialize the array that will keep track of the word lengths */
	for (int init = 0; init < MAXWORDS; init++)
	{
		wordlens[init] = 0;
	}
	/* Start tracking the characters */
	while ((c = getchar()) != EOF)
	{
		/* end of a word */
		if (c == ' ' || c == '\n' || c =='\t')
		{
			if (currwordlen > bigwordlen) 
			{
				/* 
				 * Record the word length as the biggest word. Then record the
				 * word length as standard and increase number of words by 1
				 */
				bigwordlen = currwordlen;
				wordlens[numwords] = currwordlen;
				++numwords;
				currwordlen = 0;
			}
			else 
			{
				/* 
				 * Record word length and increase number of words by 1
				 */
				wordlens[numwords] = currwordlen;
				++numwords;
				currwordlen = 0;
			}
		}
		else /* Update the current word length tracker */
			++currwordlen;
	}
	printf("\n\n\n");
	/* This will serve to loop vertically down the histogram */
	for (int i = 0; i < bigwordlen; i++)
	{
		/* Print the y-axis */
		printf("%3.0d |", bigwordlen - i);
		/* This will serve to loop through the words, or horizontally across the histogram */
		for (int j = 0; j < numwords; j++)
		{
			/* If not the last word, print a asterisk accordingly */
			if (j != numwords - 1)
			{
				if (wordlens[j] >= bigwordlen - i)
					printf(" * ");
				else
					printf("   ");
			}
			/* If last word */
			else if (j == numwords - 1)
			{
				if (wordlens[j] >= bigwordlen - i)
					printf(" * \n");
				else
					printf(" \n");
			}
		}
	}
	/* Add the x-axis lines */
	for (int k = 0; k < numwords; k++)
	{
		if (k == 0)
			printf("    +--");
		else
			printf("---");
	}
	printf("\n");
	/* Add the numbers for the x-axis */
	for (int l = 0; l < numwords; l++)
	{
		if (l == 0)
			printf("      %d", l + 1);
		else
			printf("  %d", l + 1);
	}
	return 0;
}