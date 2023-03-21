#include "main.h"

/**
 * print_last_digit - Prints the last digit of a number
 * @n: The number to be treated
 * Return: Value of the last digit of the number
 */

int print_last_digit(int n)

{
	int lst;

	lst = n % 10;
	if (lst < 0)
	{
	lst = lst * -1;
	}
	_putchar(lst + '0');
	return (lst);
}
