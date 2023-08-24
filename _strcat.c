#include "shell.h"

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
	char *temp = dest;

	while (*dest)
		dest++;

	*dest++ = '/';
	while (*src)
		*dest++ = *src++;
	return (temp);
}
