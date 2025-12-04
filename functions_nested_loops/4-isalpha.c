#include "main.h"

/**
 * _islower - checks if a character is alpha
 * @c: the character to check
 *
 * Return: 1 if c is alpha, 0 otherwise
 */


int _isalpha(int c)
{
	return ((c >= 97 && c <= 123) || (c >= 65 && c <= 90));
}
