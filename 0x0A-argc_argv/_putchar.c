#include <stdio.h>
#include "main.h"

/**
 * _putchar - writes character c to stdout
 * @c: Character to print
 *
 * Return: 1 on success.
 * On error, -1 is returned and errno appropriately set.
 */

int _putchar(char c)

{
return (write(1, &c, 1));
}
