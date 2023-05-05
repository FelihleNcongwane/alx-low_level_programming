#include "main.h"

/**
 * get_endianness - checks the endianness of the machine
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	int num = 1; /* Create a variable with the value 1 */
	char *endian = (char *)&num; /* Create a char pointer to the address of the variable */

	if (*endian == 1) /* If the first byte of the variable is 1, the machine is little endian */
		return (1);

	return (0); /* Otherwise, the machine is big endian */
}
