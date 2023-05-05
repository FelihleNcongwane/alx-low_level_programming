#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 *
 * @n: number to print in binary
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long int current;

	for (i = 63; i >= 0; i--) /* Loop through each bit of the number */
	{
		current = n >> i; /* Get the value of the bit at the current index */

		if (current & 1) /* If the bit is 1, print '1' and increment the count */
		{
			_putchar('1');
			count++;
		}
		else if (count) /* If the bit is 0 and there have been previous 1's, print '0' */
			_putchar('0');
	}
	if (!count) /* If there were no 1's, print '0' */
		_putchar('0');
}
