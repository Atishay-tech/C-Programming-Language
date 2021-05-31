/*
 * Exercise 1-12
 * Write a program that prints its input one word per line.
 */

#include <stdio.h>

#define IN 0    // Inside a word
#define OUT 1   // Outside a word

/* prints the input one word per line */
int main()
{
    int c;
    int state;  // Whether inside a word or outside

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN)
                putchar('\n');
            state = OUT;
        }
        else if (state == OUT)
            state = IN;

        if (state == IN)
            putchar(c);
    }

    return 0;
}