/**
 * binary_to_uint - converts a binary number to an unsigned integer
 * @binary: pointer to the binary number as a string
 *
 * Return: the unsigned integer value of the binary number, or 0 if binary is
 * NULL or contains a character that is not '0' or '1'
 */
unsigned int binary_to_uint(const char *binary)
{
	unsigned int decimal_value = 0;
	int index;

	if (binary == NULL)
		return (0);

	for (index = 0; binary[index] != '\0'; index++)
	{
		if (binary[index] != '0' && binary[index] != '1')
			return (0);

		decimal_value = (decimal_value << 1) | (binary[index] - '0');
	}

	return (decimal_value);
}
