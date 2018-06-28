#include<stdio.h>

#define MAXLINE 1000
#define MAXLENGTH 81

int lineget(char line[], int max);
void copy(char from[], char to[]);

int main(void)
{
	int len = 0; /* current line length */
	char line[MAXLINE]; /* current input line */

	while((len = lineget(line, MAXLINE)) > 0)
		printf("Line without tabs or spaces: %s\n", line);

	return 0;
}



int lineget(char line[], int max)
{
  	int i, c = 0; 

	while(((c = getchar()) != EOF) && c != '\n' && i < max)
	{
		if(c == '\n')
    		line[i++] = c;
		else if(c != ' ' && c != '\t')
			line[i++] = c;
	}

  	line[i] = '\0';

  	return i;
}