#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned integer
 * @binary_string: pointer to the binary number as a string
 *
 * Return: the unsigned integer value of the binary number, or 0 if binary_string
 * is NULL or contains a character that is not '0' or '1'
 */
unsigned int binary_to_uint(const char *binary_string)
{
	unsigned int decimal_value = 0;
	int index;

	if (binary_string == NULL)
		return (0);

	for (index = 0; binary_string[index] != '\0'; index++)
	{
		if (binary_string[index] != '0' && binary_string[index] != '1')
			return (0);

		decimal_value = (decimal_value << 1) | (binary_string[index] - '0');
	}

	return (decimal_value);
}
