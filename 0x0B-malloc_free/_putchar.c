#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes character c to stdout
 * @c: The character to print
 *
 * Return: 1 if successful.
 * On error, -1 is returned, and errno is appropriately set.
 */

int _putchar(char c)

{
	return (write(1, &c, 1));
}
