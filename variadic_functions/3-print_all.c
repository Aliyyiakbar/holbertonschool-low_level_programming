#include "variadic_functions.h"

/**
 * p_char - prints a char argument
 * @ap: pointer to the variadic argument list
 * @sep: separator to print before the value
 */
void p_char(va_list *ap, char *sep)
{
	printf("%s%c", sep, (char)va_arg(*ap, int));
}

/**
 * p_int - prints an int argument
 * @ap: pointer to the variadic argument list
 * @sep: separator to print before the value
 */
void p_int(va_list *ap, char *sep)
{
	printf("%s%d", sep, va_arg(*ap, int));
}

/**
 * p_float - prints a float argument
 * @ap: pointer to the variadic argument list
 * @sep: separator to print before the value
 */
void p_float(va_list *ap, char *sep)
{
	printf("%s%f", sep, va_arg(*ap, double));
}

/**
 * p_string - prints a string argument (prints (nil) if NULL)
 * @ap: pointer to the variadic argument list
 * @sep: separator to print before the value
 */
void p_string(va_list *ap, char *sep)
{
	char *s = va_arg(*ap, char *);

	if (s == NULL)
	{
		s = "(nil)";
	}

	printf("%s%s", sep, s);
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
		switch (format[i])
		{
		case 'c':
			p_char(&ap, sep);
			sep = ", ";
			break;
		case 'i':
			p_int(&ap, sep);
			sep = ", ";
			break;
		case 'f':
			p_float(&ap, sep);
			sep = ", ";
			break;
		case 's':
			p_string(&ap, sep);
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
