#include<stdio.h>

#define MAXLINE 1000
#define MAXLENGTH 80

int lineget(char line[], int max);
void copy(char from[], char to[]);

int main(void)
{
	int len, length = 0; /* current line length */
	char line[MAXLINE]; /* current input line */

	while((len = lineget(line, MAXLINE)) > 0)
		{
			printf("Reversed line: ");
			while(len > -1)
			{
				--len;
				printf("%c", line[len]);
			}
			printf("\n");
			for (int init = 0; init < MAXLINE; init++)
				{
					line[init] = 0;
				}
		}

	return 0;
}



int lineget(char line[], int max)
{
  	int i, c = 0; 

	for(i = 0; ((c = getchar()) != EOF) && c != '\n' && i < max; ++i)
		line[i] = c;

	if(c == '\n')
    	line[++i] = c;

  	line[i] = '\0';

  	return i;
}