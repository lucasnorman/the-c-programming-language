#include <stdio.h>

#define MAXLINE 1000 /* Max line length */

/* Our function to record the user input */
int inputline(char line[]);

int main(void) 
{
	int t; /* Compare against length */
	int len; /* Length of line input */
	int location; /* Keep location on each folded line */
	int spaceholder; /* Keep index of space closest to the folding point */
	int FOLDLENGTH=20; /* When to fold */
	char line[MAXLINE]; /* Current input line */

	/* Line init */
	for (int init = 0; init < MAXLINE; ++init) {
		line[init] = 0;
	}

	while ((len=inputline(line)) > 0) {
		/* Line is long so we need to fold it */
		if (len > FOLDLENGTH) {
			t = 0;
			location = 0;
			while(t < len) {
				if (line[t] == ' ')
					spaceholder = t;
				/* If the line is at the fold length, go back to the last space and place a newline */
				if (location==FOLDLENGTH) {
					line[spaceholder] = '\n';
					location = 0;
				}
				++location;
				++t;
			}
		}
		printf("%s", line);
	}
	return 0;
}

int inputline(char line[]) 
{
	int c, i;

	/* Record the user input */
	for (i = 0; i<MAXLINE-1 && ( c=getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	/* Record the newline after it breaks the for loop */
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	/* Mark the end of the line */
	line[i] = '\0';
	return i;
}