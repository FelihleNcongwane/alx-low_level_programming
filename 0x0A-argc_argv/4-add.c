#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * check_num - check - string there are digit
 * @str: an array str
 *
 * Return: 0 on Success
 */

int check_num(char *str)

{
	/*Declaring variables*/
	unsigned int count;

	count = 0;
	while (count < strlen(str)) /*count string*/

	{
		if (!isdigit(str[count])) /*check if there are digit*/
		{
			return (0);
		}

		count++;
	}
	return (1);
}

/**
 * main - Prints the name of the program
 * @argc: Counts arguments
 * @argv: The arguments
 *
 * Return: 0 on Success
 */

int main(int argc, char *argv[])

{

	/*Declaring variables*/
	int count;
	int str_to_int;
	int sum = 0;

	count = 1;
	while (count < argc) /*Scans through the whole array*/
	{
		if (check_num(argv[count]))

		{
			str_to_int = atoi(argv[count]); /*ATOI --> convert string to an int*/
			sum += str_to_int;
		}

		/*Condition if one of the number contains symbols*/
		else
		{
			printf("Error\n");
			return (1);
		}

		count++;
	}

	printf("%d\n", sum); /*prints sum*/

	return (0);
}
