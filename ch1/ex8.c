/*
 * Exercise 1-8
 * Write a program to count blanks, tabs and newline.
 */

#include <stdio.h>

/* counts the number of blanks, tabs, and newlines in input */
int main()
{
    int c;
    int nb, nt, nl;

    nb = nt = nl = 0;

    while((c = getchar()) != EOF) {
        if (c == '\n')
            ++nl;
        if (c == '\t')
            ++nt;
        if (c == ' ')
            ++nb;
    }

    printf("Number of blanks: %d \n", nb);
    printf("Number of lines: %d \n", nl);
    printf("Number of tabs: %d \n", nt);

    return 0;
}