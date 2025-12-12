#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - prints the solution for the program 101-keygen.
 *        I found the passed 2772 using dogbolt.org decompiler.
 *
 * Return: Always 0 (Success).
 */

int main(void)
{
	srand(time(0));

	printf("%d\n", rand());

	return (0);
}
