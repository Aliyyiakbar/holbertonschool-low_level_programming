#include "main.h"

/**
 * jack_bauer - Prints the solution for the task.
 *
 **/

void jack_bauer()
{
	char i, j, k, l;
	for (i = '0' ; i <= '2'; ++i)
	{
		for (j = '0'; j <= '9'; ++j)
		{
			for (k = '0'; k <= '9'; ++k)
			{
				for (l = '0'; l <= '9'; ++l)
				{
					_putchar(i);
					_putchar(j);
					_putchar(':');
					_putchar(k);
					_putchar(l);
					_putchar('\n');
				}
			}
		}
	}	
}
