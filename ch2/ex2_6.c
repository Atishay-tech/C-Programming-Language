#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    int  num;

    num = setbits(07, 5, 2, 07);
    printf("%o", num);

    return 0;
}

/* setbits: returns x with n from position p set to the rightmost n bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned mask;

    mask = ~((~0)<<n);
    y &= mask;
    y <<= p-n+1;
    mask <<= p-n+1;
    x &= ~mask;
    x |= y;

    return x;
}