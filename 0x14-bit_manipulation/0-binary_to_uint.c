#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned integer
 * @binary: pointer to the binary number as a string
 *
 * Return: the unsigned integer value of the binary number, or 0 if binary is
 * NULL or contains a character that is not '0' or '1'
 */
unsigned int binary_to_uint(const char *binary)
{
	/* Initialize variables */
	int index;
	unsigned int decimal_value = 0;

	/* Check for NULL input */
	if (binary == NULL)
		return (0);

	/* Traverse the binary string and convert to decimal */
	for (index = 0; binary[index] != '\0'; index++)
	{
		/* Check for invalid characters */
		if (binary[index] != '0' && binary[index] != '1')
			return (0);

		/* Convert binary digit to decimal */
		decimal_value = (decimal_value << 1) | (binary[index] - '0');
	}

	/* Return the decimal value of the binary string */
	return (decimal_value);
}i
