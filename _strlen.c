#include "main.h"

/**
 * _strlen - function that returns the length of a string
 *
 * @s: the string concerned
 *
 * Return: the lenth of the string
 */
int _strlen(char *s)
{
	int length = 0;

	for ( ; s[length] != '\0'; )
	{
		length++;
	}

	return (length);
}
