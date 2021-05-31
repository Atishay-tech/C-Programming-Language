/*
 * Exercise 1-9
 * Write a program to copy its input to its output,
 * replacing each string of one or more blanks by a single blank.
 */

#include <stdio.h>

#define YES 1
#define NO 0

/*
 * copies input to output
 * replacing each string of one or more string by a single blank
 */
int main()
{
    int c;
    int blank;

    blank = NO;
    while ((c = getchar()) != EOF) {
        if (c != ' ')
            blank = NO;
        if (!blank)
            putchar(c);
        if (c == ' ')
            blank = YES;
    }

    return 0;
}