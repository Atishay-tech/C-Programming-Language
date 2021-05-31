/*
 * Exercise 1-5
 * Modify the temperature conversion program to print the table in reverse order,
 * that is, from 300 degrees to 0.
 */

#include <stdio.h>

/*
 * print Fahrenheit-Celsius table
 * for fahr = 300, 280, 260, ..., 0
 */
int main()
{
    float fahr, celsius;
    int start, end, step;

    start = 300;    // starting value for fahrenhiet scale
    end = 0;        // end value
    step = 20;      // step size

    printf("Fahrenheit \t Celsius \n");
    printf("--------------------------------\n");
    for (fahr = start; fahr >= end; fahr -= step) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%9.0f \t %6.1f \n", fahr, celsius);
    }

    return 0;
}