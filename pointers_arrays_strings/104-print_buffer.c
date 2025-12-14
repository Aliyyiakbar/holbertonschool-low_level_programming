#include "main.h"
#include <stdio.h>

/**
 * print_hex_line - prints the hex part of one line
 * @b: buffer
 * @size: total size
 * @i: start index of the line
 */
void print_hex_line(char *b, int size, int i)
{
	int j;

	for (j = 0; j < 10; j++)
	{
		if (i + j < size)
		{
			printf("%02x", (unsigned char)b[i + j]);
		}
		else
		{
			printf("  ");
		}

		if (j % 2 == 1)
		{
			printf(" ");
		}
	}
}

/**
 * print_ascii_line - prints the ascii part of one line
 * @b: buffer
 * @size: total size
 * @i: start index of the line
 */
static void print_ascii_line(char *b, int size, int i)
{
	int j;
	unsigned char c;

	for (j = 0; j < 10 && i + j < size; j++)
	{
		c = (unsigned char)b[i + j];
		if (c >= 32 && c <= 126)
		{
			printf("%c", c);
		}
		else
		{
			printf(".");
		}
	}
}

/**
 * print_buffer - prints a buffer (10 bytes per line)
 * @b: buffer
 * @size: size of buffer
 */
void print_buffer(char *b, int size)
{
	int i;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);
		print_hex_line(b, size, i);
		print_ascii_line(b, size, i);
		printf("\n");
	}
}
