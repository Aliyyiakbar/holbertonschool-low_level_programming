#include <stdio.h>

/**
 * main - prints numbers from 1 to 100 with FizzBuzz rules
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;
	int fizz = 0;
	int buzz = 0;

	for (i = 1; i <= 100; i++)
	{
		fizz++;
		buzz++;

		if (i > 1)
			printf(" ");

		if (fizz == 3 && buzz == 5)
		{
			printf("FizzBuzz");
			fizz = 0;
			buzz = 0;
		}
		else if (fizz == 3)
		{
			printf("Fizz");
			fizz = 0;
		}
		else if (buzz == 5)
		{
			printf("Buzz");
			buzz = 0;
		}
		else
		{
			printf("%d", i);
		}
	}

	printf("\n");
	return (0);
}
