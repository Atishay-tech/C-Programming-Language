#include <stdio.h>

#define MAX_LEN 1024

void squeeze(char s1[], const char s2[]);
void input_string(char str[]);

void main()
{
    char s1[MAX_LEN], s2[MAX_LEN];

    printf("Enter s1:\n");
    input_string(s1);
    printf("Enter s2:\n");
    input_string(s2);

    squeeze(s1, s2);
    printf("\nNew s1:\n%s", s1);
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

/* squeeze: deletes each character in s1 that matches any character in s2 */
void squeeze(char s1[], const char s2[])
{
    char chr_list[MAX_LEN];
    int i, j, indx, chr_num;
    char c;

    /* finding all distinct characters in s2 */
    chr_num = 0;            // number of distinct characters found in s2
    for(i = 0; (c=s2[i]) != '\0'; i++) {
        for(j = 0; j < chr_num && chr_list[j] != c; j++)
            ;
        if(j == chr_num) {
            // c not found in chr_list
            chr_list[j] = c;
            ++chr_num;
        }
    }
    chr_list[chr_num] = '\0';

    /* deleting charcters from s1 */
    for(i=0, indx=0; (c=s1[i]) != '\0'; i++) {
        for(j=0; j < chr_num && c != chr_list[j]; j++)
            ;
        if(j == chr_num) {
            // c not found in chr_list
            s1[indx++] = c; 
        }
    }
    s1[indx] = '\0';
}