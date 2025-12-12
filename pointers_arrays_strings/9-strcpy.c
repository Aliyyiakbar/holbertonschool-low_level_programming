#include "main.h"

/**
 * _strcpy - Copies the string pointed to by src to dest.
 *           This includes the terminating null byte ('\0').
 * @dest: Destination buffer.
 * @src: Source string.
 *
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; ++i)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
