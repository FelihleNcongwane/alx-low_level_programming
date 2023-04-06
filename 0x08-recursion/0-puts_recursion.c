#include "main.h"

/**
 * _puts_recursion - a function like puts();
 * @s: Input
 * Return: 0 Always on Success
 */

void _puts_recursion(char *s)
{
	if (*s)
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}

	else
		_putchar('\n');
}
