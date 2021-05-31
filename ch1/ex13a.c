/*
 * Exercise 1-13
 * Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal;
 * a vertical orientation is more challenging.
 */

#include <stdio.h>

#define MAX_WORD_LENGTH 50
#define IN 1    // inside a word
#define OUT 0   // outside a word

/*
 * prints a horizontal histogram of the lengths of words in the input
 */
int main()
{
    int c, word_length;
    int state;  // whether inside a word or outside
    int freq[MAX_WORD_LENGTH + 1] = {0};

    word_length = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == ' ' || c == '\t') {
            if (state == IN) {
                ++freq[word_length];
                word_length = 0;
                state = OUT;
            }
        }
        else {
            state = IN;
            ++word_length;
        }
    }

    printf("\n Histogram: \n");
    printf("--------------------------------------------\n");
    for (int i=0; i <= MAX_WORD_LENGTH; ++i) {
        if (freq[i] > 0) {
            printf("%3d ", i);
            for (int j=0; j < freq[i]; ++j)
                printf("#");
            printf (" %d \n", freq[i]);
        }
    }

    return 0;
}