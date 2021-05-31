/*
 * Exercise 1-18
 * Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines.
 */
#include <stdio.h>

#define TRUE 1
#define FALSE 0

/*
 * removes trailing blanks and tabs from each line of input,
 * and deletes entirely blank lines
 */
int main()
{
    int c;          // present character
    int empty;      // if line is empty or not
    int trailing;   // if the current blank is trailing

    empty = TRUE;
    trailing = FALSE;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            if (!empty && !trailing) {
                putchar(' ');
                trailing = TRUE;
            }
        }
        else if (c == '\n') {
            if (!empty) {
                putchar('\n');
                empty = TRUE;
            }
        }
        else {
            trailing = FALSE;
            empty = FALSE;
            putchar(c);
        }
    }

    return 0;
}