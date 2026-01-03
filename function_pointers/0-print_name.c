#include "function_pointers.h"

/**
 * print_name - prints a name using a given function
 * @name: the name to be printed
 * @f: pointer to the function that prints the name
 */

void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
	{
		f(name);
	}
}
