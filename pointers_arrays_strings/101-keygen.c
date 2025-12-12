#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - prints the solution for the program 101-keygen.
 *        I found the passed 2772. It denotes the sum of ascii values
 *        of the password. I found it using dogbolt.org decompiler.
 *
 * Return: Always 0 (Success).
 */

int main(void)
{
	int sum;
	
	sum = 2772;
	while(sum > 'z')
	{
		printf("z");
		sum -= 'z';
	}
	printf("%c\n", sum);

	return (0);
}
