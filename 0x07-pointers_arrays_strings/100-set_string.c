#include "main.h"

/**
 * set_string - function that sets the value of a pinter
 * to a char
 * @s: pointer to a pointer
 * @to: a pointer char
 */
void set_string(char **s, char *to)
{
	*s = to;
}
