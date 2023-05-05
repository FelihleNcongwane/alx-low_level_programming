#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip to get from
 * one number to another
 *
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff = n ^ m; /* Get the XOR difference of the two numbers */
	unsigned int count = 0;

	while (diff > 0) /* Loop through the bits in the difference */
	{
		if (diff & 1) /* If the bit is 1, increment the count */
			count++;
		diff >>= 1; /* Shift the difference one bit to the right */
	}

	return (count); /* Return the count of flipped bits */
}
