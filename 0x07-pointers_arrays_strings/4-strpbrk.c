#include "main.h"

/**
 * _strpbrk - Point of Entry
 * @s: Input
 * @accept: Input
 * Return: 0 Always on Success
 */

char *_strpbrk(char *s, char *accept)

{
		int k;

		while (*s)
		{
			for (k = 0; accept[k]; k++)
			{
			if (*s == accept[k])
			return (s);
			}
		s++;
		}

	return ('\0');
}
