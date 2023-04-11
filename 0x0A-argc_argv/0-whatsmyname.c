#include <stdio.h>
#include "main.h"

/**
 * main - prints number of arguments passed to the program
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 Always on Success
 */

int main(int argc, char *argv[])
{
(void) argv; /*Ignore argv*/
	printf("%d\n", argc - 1);

	return (0);
}
