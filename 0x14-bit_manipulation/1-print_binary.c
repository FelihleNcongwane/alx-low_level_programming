#include "main.h"

/**
 * power - Function that calculates the power of a base.
 * @base: Base of the exponent.
 * @power: Power of the exponent.
 *
 * Return: Value of (base ^ power).
 */
unsigned long int power(unsigned int base, unsigned int power)
{
    unsigned long int result;
    unsigned int i;

    result = 1;
    for (i = 1; i <= power; i++)
        result *= base;
    return result;
}

/**
 * print_binary - Function that prints a number in binary notation.
 * @num: Number to print.
 *
 * Return: void
 */
void print_binary(unsigned long int num)
{
    unsigned long int divisor, check;
    char flag;

    flag = 0;
    divisor = power(2, sizeof(unsigned long int) * 8 - 1);
    while (divisor != 0)
    {
        check = num & divisor;
        if (check == divisor)
        {
            flag = 1;
            _putchar('1');
        }
        else if (flag == 1 || divisor == 1)
        {
            _putchar('0');
        }
        divisor >>= 1;
    }
}
