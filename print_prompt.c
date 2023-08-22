#include "shell.h"

/**
 * print_prompt - prints prompt to the screen
 *
 * Return: pointer to storage buffer for input
 */

char *print_prompt()
{
	size_t n = 1;
	char *buf = NULL;

	write(STDOUT_FILENO, "$ ", 2);
	getline(&buf, &n, stdin);

	return (buf);
}
