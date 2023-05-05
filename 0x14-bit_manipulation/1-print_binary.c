#include "main.h"

/**
 * print_binary - prints the binary representation of an unsigned long int
 * @n: the unsigned long int to print in binary
 */
void print_binary(unsigned long int n)
{
	/* Initialize variables */
	int i = 63;
	unsigned long int current;
	int count = 0;

	/* Traverse the binary number and print each digit */
	while (i >= 0)
	{
		/* Get the current digit */
		current = n >> i;

		/* Print the digit */
		switch (current & 1)
		{
			case true:
				_putchar('1');
				count++;
				break;
			default:
				if (count)
					_putchar('0');
				break;
		}

		/* Move to the next digit */
		i--;
	}

	/* Print '0' if the input number is 0 */
	if (!count)
		_putchar('0');
}
