#include <stdio.h>

/**
 * print_fib_rest - prints Fibonacci numbers from 93rd to 98th term
 * @f1: 91st Fibonacci number
 * @f2: 92nd Fibonacci number
 */
void print_fib_rest(unsigned long int f1, unsigned long int f2)
{
	unsigned long int f1_head, f1_tail, f2_head, f2_tail;
	unsigned long int f3_head, f3_tail;
	unsigned long int limit = 1000000000;
	int i;

	f1_head = f1 / limit;
	f1_tail = f1 % limit;
	f2_head = f2 / limit;
	f2_tail = f2 % limit;

	for (i = 93; i <= 98; i++)
	{
		f3_head = f1_head + f2_head + (f1_tail + f2_tail) / limit;
		f3_tail = (f1_tail + f2_tail) % limit;

		printf(", %lu%09lu", f3_head, f3_tail);

		f1_head = f2_head;
		f1_tail = f2_tail;
		f2_head = f3_head;
		f2_tail = f3_tail;
	}
}

/**
 * main - prints the first 98 Fibonacci numbers
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long int f1 = 1;
	unsigned long int f2 = 2;
	unsigned long int f3;
	int i;

	printf("%lu, %lu", f1, f2);

	for (i = 3; i <= 92; i++)
	{
		f3 = f1 + f2;
		printf(", %lu", f3);
		f1 = f2;
		f2 = f3;
	}

	print_fib_rest(f1, f2);

	printf("\n");
	return (0);
}
