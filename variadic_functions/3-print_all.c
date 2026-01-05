#include "variadic_functions.h"

/**
 * print_item - prints one argument depending on format char
 * @c: format specifier character
 * @ap: pointer to variadic list
 * @sep: address of separator string to print before next item
 */

void print_item(char c, va_list *ap, char **sep)
{
	char *s;

	switch (c)
	{
	case 'c':
		printf("%s%c", *sep, (char)va_arg(*ap, int));
		*sep = ", ";
		break;
	case 'i':
		printf("%s%d", *sep, va_arg(*ap, int));
		*sep = ", ";
		break;
	case 'f':
		printf("%s%f", *sep, va_arg(*ap, double));
		*sep = ", ";
		break;
	case 's':
		s = va_arg(*ap, char *);

		if (s == NULL)
		{
			s = "(nil)";
		}

		printf("%s%s", *sep, s);
		*sep = ", ";
		break;
	default:
		break;
	}
}

/**
 * print_all - prints anything, followed by a new line
 * @format: list of argument types passed to the function
 */

void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i;
	char *sep = "";

	if (format == NULL)
	{
		printf("\n");
		return;
	}

	va_start(ap, format);
	i = 0;

	while (format[i] != '\0')
	{
		print_item(format[i], &ap, &sep);
		i++;
	}

	va_end(ap);
	printf("\n");
}
