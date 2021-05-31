/*
 * Exercise 1-7
 * Write a program to print the value of EOF.
 */
#include <stdio.h>

/*
 * prints the numeric value of EOF
 *
 * Theory
 * ---------------
 * getchar returns a distinctive value when there is no more input,
 * a value that cannot be confused with any real character.
 * This value is called EOF, for ``end of file''.
 * We must declare a type big enough to hold any value that getchar returns.
 * We can't use char since variable must be big enough to hold EOF
 * in addition to any possible char. Therefore we use int.
 * 
 * EOF is an integer defined in <stdio.h>,
 * but the specific numeric value doesn't matter
 * as long as it is not the same as any char value.
 * By using the symbolic constant,
 * we are assured that nothing in the program depends on the specific numeric value.
 */
int main()
{
    printf("%d", EOF);

    return 0;
}