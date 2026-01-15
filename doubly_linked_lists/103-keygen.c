#include <stdio.h>
#include <stdlib.h>

/**
 * slen - returns length of a C string
 * @s: string
 * Return: length
 */
static int slen(const char *s)
{
	int n = 0;

	while (s && s[n])
	{
		++n;
	}

	return (n);
}

/**
 * main - keygen for crackme5
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 on usage error
 */
int main(int argc, char **argv)
{
	const char *u;
	const char *alpha;
	int len, i;
	int idx0, idx1, idx2, idx3, idx4, idx5;
	int sum, prod, sqsum;
	int maxc;
	int r;
	int n;

	if (argc != 2)
	{
		printf("Usage: %s username", argv[0]);
		exit(1);
	}

	u = argv[1];
	len = slen(u);
	alpha = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	idx0 = (len ^ 0x3b) & 0x3f;
	sum = 0;

	for (i = 0; i < len; i++)
	{
		sum += (int)(signed char)u[i];
	}

	idx1 = (sum ^ 0x4f) & 0x3f;
	prod = 1;
	for (i = 0; i < len; i++)
	{
		prod *= (int)(signed char)u[i];
	}

	idx2 = (prod ^ 0x55) & 0x3f;
	maxc = (int)(signed char)u[0];
	for (i = 0; i < len; i++)
	{
		int c = (int)(signed char)u[i];

		if (c > maxc)
		{
			maxc = c;
		}
	}
	srand((unsigned int)(maxc ^ 0x0e));
	idx3 = rand() & 0x3f;

	sqsum = 0;
	for (i = 0; i < len; i++)
	{
		int c = (int)(signed char)u[i];

		sqsum += c * c;
	}
	idx4 = (sqsum ^ 0xef) & 0x3f;

	n = (int)(signed char)u[0];
	r = 0;
	for (i = 0; i < n; i++)
	{
		r = rand();
	}
	idx5 = (r ^ 0xe5) & 0x3f;

	printf("%c%c%c%c%c%c",
	       alpha[idx0], alpha[idx1], alpha[idx2],
	       alpha[idx3], alpha[idx4], alpha[idx5]);

	return (0);
}
