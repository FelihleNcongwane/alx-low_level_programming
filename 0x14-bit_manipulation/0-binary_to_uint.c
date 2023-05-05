#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to the binary number as a string
 *
 * Return: the unsigned int value of the binary number, or 0 if b is NULL or
 * contains a character that is not '0' or '1'
 */
unsigned int binary_to_uint(const char *b)
{
	/* Initialize variables */
	unsigned int decimal_value = 0;
	int i = 0;

	/* Check for NULL input */
	switch (b == NULL)
	{
		case true:
			return (0);
		default:
			break;
	}

	/* Traverse the binary string and convert to decimal */
	while (b[i] != '\0')
	{
		/* Check for invalid characters */
		switch (b[i])
		{
			case '0':
				/* Do nothing */
				break;
			case '1':
				/* Convert binary digit to decimal */
				decimal_value = (decimal_value << 1) | 1;
				break;
			default:
				return (0);
		}

		/* Move to next character in string */
		i++;
	}

	/* Return the decimal value of the binary string */
	return (decimal_value);
}
