/*
 * Exercise 1-15
 * Rewrite the temperature conversion program of Section 1.2
 * to use a function for conversion.
 */
#include <stdio.h>

#define LOWER 0      // lower limit for fahr
#define UPPER 300    // upper limit
#define STEP 20      // step size

float fahr_to_celsius(float fahr);

/*
 * prints a Fahrenheit-Celsius table
 * for fahr = 0, 20, 40, ..., 300
 */
int main()
{
    float fahr;

    printf("Fahrenheit \t Celsius \n");
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%8.0f \t %6.1f \n", fahr, fahr_to_celsius(fahr));

    return 0;
}

/*
 * fahr_to_celsius: converts temperature from fahrenheit to celsius
 */
float fahr_to_celsius(float fahr)
{
    float celsius = (5.0/9.0) * (fahr-32.0);

    return celsius;
}