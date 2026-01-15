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
 * calc_0_2 - calculate idx0, idx1, idx2
 * @u: username
 * @len: length of username
 * @idx0: output
 * @idx1: output
 * @idx2: output
 */
static void calc_0_2(const char *u, int len, int *idx0, int *idx1, int *idx2)
{
	int i;
	int sum;
	int prod;

	*idx0 = (len ^ 0x3b) & 0x3f;
	sum = 0;

	for (i = 0; i < len; i++)
	{
		sum += (int)(signed char)u[i];
	}

	*idx1 = (sum ^ 0x4f) & 0x3f;
	prod = 1;

	for (i = 0; i < len; i++)
	{
		prod *= (int)(signed char)u[i];
	}

	*idx2 = (prod ^ 0x55) & 0x3f;
}

/**
 * calc_3_5 - calculate idx3 and idx5 (uses srand/rand)
 * @u: username
 * @len: length of username
 * @idx3: output
 * @idx5: output
 */
static void calc_3_5(const char *u, int len, int *idx3, int *idx5)
{
	int i;
	int maxc;
	int r;
	int n;

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
	*idx3 = rand() & 0x3f;

	n = (int)(signed char)u[0];
	r = 0;

	for (i = 0; i < n; i++)
	{
		r = rand();
	}

	*idx5 = (r ^ 0xe5) & 0x3f;
}

/**
 * calc_4 - calculate idx4
 * @u: username
 * @len: length of username
 * Return: idx4
 */
static int calc_4(const char *u, int len)
{
	int i;
	int sqsum;

	sqsum = 0;

	for (i = 0; i < len; i++)
	{
		int c = (int)(signed char)u[i];

		sqsum += c * c;
	}

	return ((sqsum ^ 0xef) & 0x3f);
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
	int len;
	int idx0, idx1, idx2, idx3, idx4, idx5;

	if (argc != 2)
	{
		printf("Usage: %s username", argv[0]);
		exit(1);
	}

	u = argv[1];
	len = slen(u);
	alpha = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	calc_0_2(u, len, &idx0, &idx1, &idx2);
	calc_3_5(u, len, &idx3, &idx5);
	idx4 = calc_4(u, len);

	printf("%c%c%c%c%c%c",
	       alpha[idx0], alpha[idx1], alpha[idx2],
	       alpha[idx3], alpha[idx4], alpha[idx5]);

	return (0);
}
