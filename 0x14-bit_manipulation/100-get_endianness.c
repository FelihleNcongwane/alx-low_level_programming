#include "main.h"

/**
 * get_endianness - Function that checks the endianness of the system.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
    int check_value;
    char *check_pointer;

    check_value = 1;
    check_pointer = (char *)&check_value;
    return (*check_pointer);
}
