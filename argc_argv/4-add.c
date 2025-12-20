#include <stdio.h>

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 * Return: the integer value
 */

int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int result = 0;

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
 * main - adds positive numbers passed as arguments.
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	int sum = 0;
	int i, num;

	if (argc < 2)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		num = _atoi(argv[i]);
		if (num < 0)
		{
			printf("Error\n");
			return (1);
		}
		sum += num;
	}

	printf("%d\n", sum);

	return (0);
}
