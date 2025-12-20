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
 * main -  prints the minimum number of coins to
 *         make change for an amount of money
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	int num, sum;

	sum = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	num = _atoi(argv[1]);

	if (num < 0)
	{
		printf("0\n");
		return (0);
	}

	sum += num / 25;
	num %= 25;
	sum += num / 10;
	num %= 10;
	sum += num / 5;
	num %= 5;
	sum += num / 2;
	num %= 2;
	sum += num / 1;

	printf("%d\n", sum);

	return (0);
}
