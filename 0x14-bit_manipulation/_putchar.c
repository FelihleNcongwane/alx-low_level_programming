#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes a character to stdout
 * @c: the character to write
 *
 * Return: 1 on success, or -1 on failure
 */
int _putchar(char c)
{
	/* Write the character to stdout */
	if (write(1, &c, 1) == -1)
		return (-1);

	/* Return success */
	return (1);
}
