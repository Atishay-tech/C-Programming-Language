/*
 * Exercise 2-1
 * Write a program to determine the ranges of char, short, int, and long variables,
 * both signed and unsigned, by printing appropriate values from standard headers and by direct computation.
 * Harder if you compute them: determine the ranges of the various floating-point types.
 */

#include <stdio.h>
#include <limits.h>


/*
 * prints range of char, short, int, and long by direct computation
 */
int main()
{
    printf("Char: %d : %d \n",
                (char)(((unsigned char)~0 >> 1) + 1),
                (char)((unsigned char)~0 >> 1) );
    printf("UChar: %d : %d \n",
                (unsigned char)0,
                (unsigned char)~0 );
    printf("Short: %d : %d \n",
                (short)(((unsigned short)~0 >> 1) + 1),
                (short)((unsigned short)~0 >> 1) );
    printf("UShort: %u : %u \n",
                (unsigned short)0,
                (unsigned short)~0 );
    printf("Int: %d : %d \n",
                (int)(((unsigned int)~0 >> 1) + 1),
                (int)((unsigned int)~0 >> 1) );
    printf("UInt: %u : %u \n",
                (unsigned int)0,
                (unsigned int)~0 );
    printf("Long: %ld : %ld \n",
                (long)(((unsigned long)~0 >> 1) + 1),
                (long)((unsigned long)~0 >> 1) );
    printf("ULong: %lu : %lu \n",
                (unsigned long)0,
                (unsigned long)~0 );

    return 0;
}