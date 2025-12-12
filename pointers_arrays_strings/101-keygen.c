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
	srand(time(0));

	char s[] = "abcdefghijklmabcdefghijklm0.";

	int i, j;

	i = rand() % 29;
	j = rand() % 29;

	char tmp;

	tmp = s[i];
	*(s + i) = s[j];
	*(s + j) = tmp;

	printf("%s\n", s);

	return (0);
}
