#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers
 *
 * Description: The sequence starts with 1 and 2.
 * The numbers are separated by a comma and a space.
 *
 * Return: Always 0.
 */
int main(void)
{
	long int a = 1;
	long int b = 2;
	long int next;
	int i;

	printf("%ld, %ld", a, b);

	for (i = 3; i <= 50; i++)
	{
		next = a + b;
		printf(", %ld", next);
		a = b;
		b = next;
	}

	printf("\n");
	return (0);
}
