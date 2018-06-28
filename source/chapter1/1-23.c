#include <stdio.h>

#define MAXLINE 1000 /* Maximum line length */

int inputline(char line[]); /* Function prototype */

int main(void) 
{
	int i, len, first, last;
	char line[MAXLINE]; /* Current line */
	
	len = first = last = 0;
	while ((len = inputline(line)) > 0) {
		i = 0;
		while (i < len) {
			if (line[i] == '/' && line[i+1] == '*') { /* Test */
				first = i;
				++i;
				while (first != last) {
					++i;
					if (line[i] == '*' && line[i+1] == '/') {
						++i;
						last = i;
						while (first <= last) {
							line[first] = ' ';
							putchar(line[first]);
							++first;
						}
						first = last = 0;
					}
				}
			/* What will this do */
			} /* How about here */
				++i;
		} /* Remove this? */
	printf("\n%s", line);
	}
	return 0;
}

int inputline(char line[])
{
	int c, i;

	/* Init line */
	for (int init = 0; init < MAXLINE-1; ++init) {
		line[init] = 0;
	}

	for (i = 0; i < MAXLINE-1 && (c=getchar()) != EOF; ++i)
		line[i] = c;
	line[i] = '\0';
	return i;
}