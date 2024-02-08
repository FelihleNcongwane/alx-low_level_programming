#include "main.h"

/**
 * convertBinaryToUnsignedInt - Function that converts a binary number to an unsigned int.
 * @binary: Pointer to a string containing a binary number.
 *
 * Return: Unsigned int with the decimal value of the binary number, or 0 if there is an error.
 */
unsigned int convertBinaryToUnsignedInt(const char *binary)
{
    int index;
    unsigned int decimal;

    decimal = 0;

    if (!binary)
        return 0;

    for (index = 0; binary[index] != '\0'; index++)
    {
        if (binary[index] != '0' && binary[index] != '1')
            return 0;
    }

    for (index = 0; binary[index] != '\0'; index++)
    {
        decimal <<= 1;
        if (binary[index] == '1')
            decimal += 1;
    }

    return decimal;
}
