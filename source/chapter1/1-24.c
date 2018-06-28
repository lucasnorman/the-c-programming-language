#include <stdio.h>

#define MAXLINE 1000 /* Max length */

int inputline(char line[]);

int main(void) {
	int i;
	int len; /* Keep track of line length */
	int paranthesis, bracket, singquote, doubquote, comment; /* Keep track of of syntax error numbers */
	char line[MAXLINE]; /* Record the input */
	char parindex[MAXLINE]; /* Get the position of the error. Same for below. */
	char brackindex[MAXLINE];
	char singindex[1];
	char doubindex[1];
	char commindex[MAXLINE];
	int j, k, l, m, n; /* Keep track of syntax error index positions */

	/* Init the arrays */
	for (int init = 0; init < MAXLINE-1; ++init) {
		parindex[init] = 0;
	}

	for (int init = 0; init < MAXLINE-1; ++init) {
		brackindex[init] = 0;
	}

	singindex[0] = 0;

	doubindex[0] = 0;

	for (int init = 0; init < MAXLINE-1; ++init) {
		commindex[init] = 0;
	}

	singquote = doubquote = 1;
	i = j = k = l = m = n = paranthesis = bracket = 0;
	while ((len = inputline(line)) > 0)
		while (i < len) {
				if (line[i] == '(') {
					++paranthesis;
					/* Haven't learned continue at this point */
					parindex[j++] = i;
				}
				if (line[i] == ')') {
					--paranthesis;
					if (j == 0)
						parindex[j++] = i;
					else
						parindex[--j] = 0;
				}
				if (line[i] == '[') {
					++bracket;
					brackindex[k++] = i;
				}
				if (line[i] == ']') {
					--bracket;
					if (k == 0)
						brackindex[k++] = i;
					else
						brackindex[--k] = 0;
				}
				if (line[i] == '\'') {
					singquote *= -1;
					if (singquote == -1) 
						singindex[l++] = i;
					else
						singindex[--l] = 0;
				}
				if (line[i] == '\"') {
					doubquote *= -1;
					if (doubquote == -1) 
						doubindex[m++] = i;
					else
						doubindex[--m] = 0;
				}
				if (line[i] == '/' && line[i+1] == '*') {
					++comment;
					commindex[n++] = i;
				}
				if (line[i] == '*' && line [i+1] == '/') {
					--comment;
					if (n == 0)
						commindex[n++] = i;
					else
						commindex[--n] = 0;
				}
			}
	if (paranthesis > 0) {
		printf("You have %d unclosed paranthesis. See line(s):\n", paranthesis);
		for (int track = 0; track < j; ++j)
			printf("%d\n", parindex[track]);
	}
	if (paranthesis < 0) {
		printf("You have %u paranthesis that don't have an opening (. See line(s):\n", paranthesis);
		for (int track = 0; track < j; ++j)
			printf("%d\n", parindex[track]);
	}
	if (bracket > 0) {
		printf("You have %d unclosed brackets. See line(s):\n", bracket);
		for (int track = 0; track < k; ++k)
			printf("%d\n", brackindex[track]);
	}
	if (bracket < 0) {
		printf("You have %u brackets that don't have an opening [. See line(s):\n", bracket);
		for (int track = 0; track < k; ++k)
			printf("%d\n", brackindex[track]);
	}
	if (singquote == -1) {
		printf("You have an unclosed single quote. See line:\n");
		printf("%d\n", singindex[0]);
	}
	if (doubquote == -1) {
		printf("You have an unclosed double quote. See line:\n");
		printf("%d\n", doubindex[0]);
	}
	if (comment > 0) {
		printf("You have %d unclosed comments. See line(s):\n", comment);
		for (int track = 0; track < n; ++n)
			printf("%d\n", commindex[track]);
	}
	if (comment < 0) {
		printf("You have %u comments that don't have an opening /*. See line(s):\n", comment);
		for (int track = 0; track < n; ++n)
			printf("%d\n", commindex[track]);
	}

	return 0;
}

int inputline(char line[]) {

	int c, i;

	/* Init line */
	for (int init = 0; init < MAXLINE-1; ++init) {
		line[init] = 0;
	}

	for (i=0; (c = getchar()) != EOF; ++i)
		line[i] = c;
	line[i] = '\0';
	return i;
}