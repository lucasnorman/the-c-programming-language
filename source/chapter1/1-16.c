#include <stdio.h>
#define MAXLINE 20	/* maximum input line size */

int currline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main(void)
{
	int len;	/* current line length */
	int max;	/* maximum length seen so far */
	char line[MAXLINE];		/* current input line */
	char longest[MAXLINE];		/* longest line save here */

	len = max = 0;
	while ((len = currline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0)	/* there was a line */
		if (max > MAXLINE)
			printf("Over maximum characters allowed per line for line starting in:\n%s", longest);
		else
			printf("Longest line:\n%s", longest);
	printf("\n");
	return 0;
}

/* getline: read a line into s, return length */
int currline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (i >= lim-1) {
		s[i] = '\0';
		while((c=getchar())!=EOF && c!='\n')
			++i;
	}
	else {
		if (c == '\n') {
			s[i] = c;
			++i;
		}
		s[i] = '\0';
	}
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}