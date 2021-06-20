/*
 * Exercise 2-1
 * Write a program to determine the ranges of char, short, int, and long variables,
 * both signed and unsigned, by printing appropriate values from standard headers and by direct computation.
 * Harder if you compute them: determine the ranges of the various floating-point types.
 */

#include <stdio.h>
#include <limits.h>


/*
 * prints range of char, short, int, and long from limits.h
 */
int main()
{
    printf("Char: %d : %d \n", CHAR_MIN, CHAR_MAX);
    printf("UChar: %d : %d \n", 0, UCHAR_MAX);
    printf("Short: %d : %d \n", SHRT_MIN, SHRT_MAX);
    printf("UShort: %u : %u \n", 0, USHRT_MAX);
    printf("Int: %d : %d \n", INT_MIN, INT_MAX);
    printf("UInt: %u : %u \n", 0, UINT_MAX);
    printf("Long: %ld : %ld \n", LONG_MIN, LONG_MAX);
    printf("ULong: %lu : %lu \n", (unsigned long)0, ULONG_MAX);

    return 0;
}