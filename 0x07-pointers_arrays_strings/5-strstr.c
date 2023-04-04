#include "main.h"

/**
 * _strstr - Point of Entry
 * @haystack: Input
 * @needle: Input
 * Return: 0 Always on Success
 */

char *_strstr(char *haystack, char *needle)

{
	for (; *haystack != '\0'; haystack++)
	{
		char *l = haystack;
		char *p = needle;

		while (*l == *p && *p != '\0')
		{
			l++;
			p++;
		}

		if (*p == '\0')
			return (haystack);
	}

	return (0);
}
