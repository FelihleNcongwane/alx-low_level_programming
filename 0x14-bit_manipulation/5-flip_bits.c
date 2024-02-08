#include "main.h"

/**
 * flip_bits - Function that counts the number of bits to change
 *             to get from one number to another.
 * @n: First number.
 * @m: Second number.
 *
 * Return: Number of bits to change.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    int index;
    unsigned int countbits = 0;
    unsigned long int current;
    unsigned long int exclusive = n ^ m;

    for (index = 63; index >= 0; index--)
    {
        current = exclusive >> index;
        if (current & 1)
            countbits++;
    }

    return (countbits);
}
