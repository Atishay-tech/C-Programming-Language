/* 
 * Exercise 1-4
 * Write a program to print the corresponding Celsius to Fahrenheit table.
 */

#include <stdio.h>

/* 
 * print Celsius-Fahrenheit table
 * for celsius = 0, 20, 40, ..., 300
 */
int main()
{
    float celsius, fahr;
    int lower, upper, step;

    lower = 0;      // lower limit for celsius
    upper = 300;    // upper limit
    step = 20;      // step size

    printf("Celsius \t Fahrenheit\n");
    printf("------------------------------\n");

    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%6.0f %18.1f \n", celsius, fahr);
        celsius += step;
    }

    return 0;
}