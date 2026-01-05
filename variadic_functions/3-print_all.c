#include "variadic_functions.h"

/**
 * print_all - prints anything, followed by a new line
 * @format: list of argument types passed to the function
 */

void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	char *sep = "";
	char *s;

	if (format == NULL)
	{
		printf("\n");
		return;
	}

	va_start(ap, format);

	while (format[i] != '\0')
	{
		switch (format[i])
		{
			case 'c':
				printf("%s%c", sep, (char)va_arg(ap, int));
				sep = ", ";
				break;
			case 'i':
				printf("%s%d", sep, va_arg(ap, int));
				sep = ", ";
				break;
			case 'f':
				printf("%s%f", sep, va_arg(ap, double));
				sep = ", ";
				break;
			case 's':
				s = va_arg(ap, char *);

				if (s == NULL)
				{
					s = "(nil)";
				}

				printf("%s%s", sep, s);
				sep = ", ";
				break;
			default:
				break;
		}
		i++;
	}

	va_end(ap);
	printf("\n");
}
