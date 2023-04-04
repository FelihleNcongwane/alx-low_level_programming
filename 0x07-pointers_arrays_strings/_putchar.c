#include "main.h"
#include <unistd.h>

/**
 * _putchar - writing the character c to stdout
 * @c: The character we print
 *
 * Return: 1 on success
 * On error,we return -1, and errno appropriately set.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
