/*
 * Exercise 1-14
 * Write a program to print a histogram 
 * of the frequencies of different characters in its input.
 */

#include <stdio.h>

#define MAX_CHAR 255    // highest char value

/*
 * prints a histogram of the frequencies of the characters in input
 */
int main()
{
    int c;
    int freq[MAX_CHAR + 1] = {0};

    while ((c = getchar()) != EOF)
        ++freq[c];

    printf("\n Histogram: \n");
    printf("--------------------------------------------\n");
    for (int i=0; i <= MAX_CHAR; ++i) {
        if (freq[i] > 0) {
            printf("%2c ", i);
            for (int j=0; j < freq[i]; ++j)
                printf("#");
            printf (" %d \n", freq[i]);
        }
    }

    return 0;
}