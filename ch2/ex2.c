/*
 * Exercise 2-2
 * Write a loop equivalent to the for loop above without using && or ||.
 * for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 *      s[i] = c;
 */

#include <stdio.h>

#define MAXLEN 100  // maximum length of line
enum boolean {NO, YES};

int getline(char line[], int lim);


/* stores a line from input and then prints it */
int main()
{
    char line[MAXLEN+1];    // line buffer

    getline(line, MAXLEN+1);
    printf("%s", line);

    return 0;
}


/*
 * getline: takes a line from input and stores it into 'line'
 *          'lim' is the max number of chars that can be stored in 'line';
 *          returns the length of the line
 */
int getline(char line[], int lim)
{
    int i = 0;          // index counter
    char c;             // present character
    int loop_end = NO;  // loop condition

    i = 0;
    while (!loop_end) {
        c = getchar();

        if (c == '\n')
            loop_end = YES;
        else if (c == EOF)
            loop_end = YES;
        else if (i >= lim-1)
            loop_end = YES;
        else {
            line[i] = c;
            ++i;
        }
    }
    line[i] = '\0';
    
    return i;
}