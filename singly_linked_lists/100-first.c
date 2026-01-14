#include "lists.h"

/**
 * beforeMain - prints a message before main runs
 */
void beforeMain(void) __attribute__((constructor));

/**
 * beforeMain - prints a message before main runs
 */
void beforeMain(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
