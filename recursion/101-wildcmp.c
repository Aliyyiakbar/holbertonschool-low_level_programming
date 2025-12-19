#include "main.h"

/**
 * wildcmp - compares two strings
 * @s1: pointer to the string
 * @s2: pointer to the string
 * Return: 1 if the strings can be considered identical, 0 otherwise
 */

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1);
	}
	if (*s2 == '*')
	{
		if (*(s2 + 1) != '\0' && *s1 == '\0')
		{
			return (0);
		}
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
	}
	if (*s1 == *s2)
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}

	return (0);
}
