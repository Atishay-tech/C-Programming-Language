/*
 * Exercise 1-10
 * Write a program to copy its input to its output,
 * replacing each tab by \t, each backspace by \b, and each backslash by \\.
 * This makes tabs and backspaces visible in an unambiguous way.
 */

#include <stdio.h>

#define YES 1
#define NO 0

/* 
 * replaces each tab in input by \t, 
 * each backspace in input by \b,
 * and each backslash in input by \\.
 */
int main()
{
    int c;
    int char_replaced;

    while ((c = getchar()) != EOF) {
        char_replaced = NO;

        if (c == '\t') {
            putchar('\\');
            putchar('t');
            char_replaced = YES;
        }
        if (c == '\\') {
            putchar('\\');
            putchar('\\');
            char_replaced = YES;
        }
        if (c == '\b') {
            putchar('\\');
            putchar('b');
            char_replaced = YES;
        }
        if (!char_replaced) {
            putchar(c);
        }
    }

    return 0;
}