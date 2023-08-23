#include "main.h"

/**
 * _strcat - function that concatenates two strings
 *
 * @dest: pointer to the destination string
 * @src: pointer to the source string
 *
 * Return: a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int length = 0;

	while (dest[length] != '\0')
	{
		length++;
	}

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[length + i] = src[i];
	}
	dest[length + i] = '\0';

	return (dest);
}
