/* 
 * Exercise 1-16
 * Revise the main routine of the longest-line program
 * so it will correctly print the length of arbitrary long input lines,
 * and as much as possible of the text.
 */
#include <stdio.h>

#define MAXLINE 1000 // Maximum number of characters in line
#define IN 1    // inside a line
#define OUT 0   // outside a line


int getline(char line[], int maxline);
void copy(char to[], char from[]);


/* 
 * prints the length of longest input line and
 * the charcters of line upto a fixed limit
 */
int main()
{
    char line[MAXLINE];      // current line characters upto buffer limit
    char temp[MAXLINE];      // tmporary buffer
    char longest[MAXLINE];   // longest line saved
    int len;            // current line length inside buffer
    long total_len;     // total length of line
    long max;           // maximum length seen so far
    int state;          // whether inside a line or outside

    max = 0;
    total_len = 0;
    state = OUT;
    while ((len = getline(temp, MAXLINE)) > 0) {
        if (len == MAXLINE-1 && temp[MAXLINE-2] != '\n') {
            if (state == OUT) {
                state = IN;
                copy(line, temp);
            }
            total_len += len;
        }
        else {
            state = OUT;
            total_len += len;
        }

        if (state == OUT) {
            if (total_len > max) {
                max = total_len;
                copy(longest, line);
            }
            total_len = 0;
        }
    }

    if (max > 0) {
        printf("Longest length: %d \n", max);
        printf("%s", longest);
    }

    return 0;
}


/*
 * getline: reads a line into the buffer 'line';
 *          returns the length of line
 */
int getline(char line[], int lim)
{
    int c, i;

    for (i=0; (i < lim-1) && (c=getchar())!=EOF && c!='\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}


/*
 * copy: copies the contents of 'from' to 'to';
 *       assuming 'to' is big enough
 */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
    
    return;
}