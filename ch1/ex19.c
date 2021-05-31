/*
 * Exercise 1-19
 * Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time.
 */

#include <stdio.h>

#define MAXLINE 1000    // max length of the string

void reverse(char s[]);
int getline(char s[], int lim);

/*
 * reverses the input a line at a time
 */
int main()
{
    char line[MAXLINE+1];
    int len;

    while (getline(line, MAXLINE+1)) {
        reverse(line);
        printf("%s\n", line);
    }

    return 0;
}


/*
 * reverse: reverses the given string 's'
 */
void reverse(char s[])
{
    char temp;
    int i, j;

    j = 0;
    while (s[j] != '\0')
        ++j;
    --j;

    i = 0;
    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        
        ++i;
        --j;
    }
}


/*
 * getline: stores the next line from input into 's',
 *          'lim' is the maximum characters in 's';
 *          returns the length of the line
 */
int getline(char s[], int lim)
{
    int i;
    int c;

    i = 0;
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    s[i] = '\0';

    return i;
}