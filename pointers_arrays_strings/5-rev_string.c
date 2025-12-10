#include "main.h"

/**
 * rev_string - Reverses a string.
 * @s: pointer to the string to be reversed
 */

void rev_string(char *s)
{	
	int i, ln;

	while (s[i] != '\0')
	{
		++i;
	}
	
	ln = i;
	--i;

	char tmp[ln];

	for (; i >= 0; --i)
	{
		tmp[ln - i - 1] = s[i];
	}
	*s = *tmp;
}
