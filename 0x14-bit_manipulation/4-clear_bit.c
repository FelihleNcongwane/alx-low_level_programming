#include "main.h"

/**
 * clear_bit - sets the value of a bit at a given index to 0
 *
 * @n: number to modify
 * @index: index of the bit
 *
 * Return: 1 on success, -1 on failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63) /* If the index is greater than 63, return -1 */
		return (-1);

	*n &= ~(1 << index); /* Set the bit at the given index to 0 */

	return (1); /* Return 1 to indicate success */
}
