#include "main.h"

/**
 * set_string - the value of a pointer to a char is set
 * @s: a pointer to pointer
 * @to: pointer char.
 */

void set_string(char **s, char *to)

{
	*s = to;
}
