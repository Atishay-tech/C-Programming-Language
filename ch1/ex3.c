/* 
 * Exercise 1-3 
 * Modify the temperature conversion program to print a heading above the table.
 */

#include <stdio.h>

/*
 * print Fahrenite-Celsius table
 * for fahr = 0, 20, 40, ..., 300
 */
void main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      // lower limit on temperature scale
    upper = 300;    // upper limit
    step = 20;      // step size

    printf("Fahrenheite \t Celsius\n");
    printf("-----------------------------\n");
    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%10.0f %12.1f\n", fahr, celsius);
        fahr += step;
    }
}