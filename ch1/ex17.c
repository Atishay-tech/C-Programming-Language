/*
 * Exercise 1-17
 * Write a program to print all input lines that are longer than 80 characters.
 */

#include <stdio.h>

#define MAXLINE 1000    // max number of characters in line
#define IN 1            // inside a line
#define OUT 0           // outside a line
#define THRESHOLD 80    // minimum length of lines to print

int getline(char line[], int maxline);

/*
 * prints all lines longer than 80 characters
 */
int main()
{
    char line[MAXLINE]; // current line
    int len;    // length of current line
    int state;  // wheter inside a line or outside

    state = OUT;
    while ((len = getline(line, MAXLINE)) > 0) {
        if (len == MAXLINE-1 && line[MAXLINE-2] != '\n')
            state = IN;
        else
            state = OUT;
            
        if (state == OUT && len > THRESHOLD)
            printf("%s", line);
        if (state == IN)
            printf("%s", line);
    }

    return 0;
}


/*
 * getline: inputs a line into 'line';
 *          returns the length of the line
 */
int getline(char line[], int lim)
{
    int i, c;

    for (i=0; (i<lim-1) && (c = getchar())!=EOF && (c!='\n'); ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = '\n';
        ++i;
    }
    line[i] = '\0';

    return i;
}