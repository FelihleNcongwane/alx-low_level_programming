#include "main.h"

/**
 * get_bit - returns the value of a bit at an index in a decimal number
 *
 * @n: number to search
 * @index: index of the bit
 *
 * Return: value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_value;

	if (index > 63) /* If the index is greater than 63, return -1 */
		return (-1);

	bit_value = (n >> index) & 1; /* Get the value of the bit at the given index */

	return (bit_value); /* Return the value of the bit */
}
