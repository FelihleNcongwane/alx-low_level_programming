#include "main.h"

/**
 * _memset -we  fill a block of memory with a specific value
 * @s: the start address of memory to be filled
 * @b: desired value
 * @n: bytes number to be changed
 *
 * Return: array with new values for n bytes
 */

char *_memset(char *s, char b, unsigned int n)

{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
