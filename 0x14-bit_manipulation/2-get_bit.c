#include "main.h"

/**
 * get_bit - gets the bit value at a given index
 * @n: the number to get the bit from
 * @index: the index of the bit to get, starting from 0
 *
 * Return: the value of the bit at index, or -1 if an error occurs
 */
int get_bit(unsigned long int n, unsigned int index)
{
	/* Check for invalid index */
	switch (index > 63)
	{
		case true:
			return (-1);
		default:
			break;
	}

	/* Get the value of the bit at the given index */
	int bit_value = (n >> index) & 1;

	/* Return the value of the bit */
	return (bit_value);
}
