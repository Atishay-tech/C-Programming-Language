#include <stdio.h>
#include <ctype.h>

int htoi(const char hex[]);
int todecimal(char hex);

int main()
{
    char hex[100];  // number in hexadecimal

    printf("Enter the hexadecimal number: ");

    scanf("%s", hex);
    printf("Number in decimal: %d\n", htoi(hex));

    return 0;
}

/* htoi: converts a string of hexadecimal digits to an equivalent integer value */
int htoi(const char hex[])
{
    char c;
    int i, num;

    /* for initial trailing zeroes or spaces */
    for(i = 0; hex[i]=='0' || hex[i]==' ' ; i++)
        ;
    /* for initial 0x or 0X */
    if(i >= 1 && hex[i-1] == '0') {
        if(hex[i]=='x' || hex[i]=='X')
            ++i;
    }

    /* main loop */
    num = 0;            // value of number in decimal
    while((c=hex[i]) != '\0' && isxdigit(c)) {
        if(c == ' ')
            ++i;
        else {
            num = num*16 + todecimal(c);
            ++i;
        }
    }

    /* loop ended due to invalid hexadecimal digit */
    if(c != '\0')
        printf("\nNot a valid hexadecimal number\n");

    return num;
}

/* todecimal: converts a hexadecimal character to its equivalent decimal value */
int todecimal(char hex)
{
    int i, values[16], index;

    for(i = 0; i < 16; i++)
        values[i] = i;

    if('0' <= hex && hex <= '9')
        index = hex-'0';
    else if('a' <= hex  && hex <= 'f')
        index = 10+hex-'a';
    else if('A' <= hex && hex <= 'F')
        index = 10+hex-'A';
    else {
        printf("\nNot a hexadecimal character\n");
        return -1;
    }

    return values[index];
}