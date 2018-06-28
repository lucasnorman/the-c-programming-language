#include <stdio.h>

int main(void)
{
    int c, d;

    while ((c=getchar()) != EOF) {
        d = 0;
        if (c == '\\') {
            putchar('\\');
            d = 1;
        }
        if (c == '\t') {
            putchar('t');
            d = 1;
        }
        if (c == '\b') {
            putchar('b');
            d = 1;
        }
        if (d == 0)
            putchar(c);        
    }
    return 0;
}