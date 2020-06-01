#include <stdio.h>

#define MAX_LEN 1024

int any(const char s1[], const char s2[]);
void input_string(char str[]);

void main()
{
    char s1[MAX_LEN], s2[MAX_LEN];

    printf("Enter s1:\n");
    input_string(s1);
    printf("Enter s2:\n");
    input_string(s2);

    printf("\nOutput: %d\n", any(s1, s2));
}

/* input_string: stores all characters from buffer to str[] until EOF */
void input_string(char str[])
{
    int i;
    int c;

    for(i = 0; i < MAX_LEN-1 && (c=getchar()) != EOF; i++)
        str[i] = c;
    str[i] = '\0';
}

/* any: returns the first location in a string s1 where any character from the string s2 occurs,
 *      -1 if s1 contains no characters from s2 . */
int any(const char s1[], const char s2[])
{
    int i, j;

    for(i = 0; s1[i] != '\0'; i++) {
        for(j = 0; s2[j] != '\0'; j++) {
            if(s1[i] == s2[j])
                return i;
        }
    }
    
    return -1;
}