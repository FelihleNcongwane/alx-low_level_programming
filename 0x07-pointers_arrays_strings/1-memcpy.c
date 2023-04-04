#include "main.h"

/**
 *_memcpy - a functio coping memory area
 *@dest: storage memory
 *@src: where it is copied
 *@n: bytes number
 *
 *Return: memory copied with changed n bytes
 */

char *_memcpy(char *dest, char *src, unsigned int n)

{
	int r = 0;
	int i = n;

	for (; r < i; r++)
	{
		dest[r] = src[r];
		n--;
	}
	return (dest);
}
