#include <stdio.h>

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 * Return: the integer value
 */

unsigned long int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	unsigned long int result = 0;

	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
	{
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}

	return (sign * result);
}

/**
 * main - multiplies two BIG numbers passed as arguments.
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	unsigned long int num1, num2, product;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	num1 = (unsigned long int)_atoi(argv[1]);
	num2 = (unsigned long int)_atoi(argv[2]);
	product = num1 * num2;
	
	printf("%lu\n", product);
	
	return (0);
}
