#include "main.h"

/**
 * rev_string - Reverses a string.
 * @s: pointer to the string to be reversed
 */

void rev_string(char *s)
{	
	int i, j;

	i = 0;

	while (s[i] != '\0')
	{
		++i;
	}
	
	j = 0;
	--i;

	while(i > j)
	{
		char tmp;

		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;

		--i;
		++j;
	}
}
